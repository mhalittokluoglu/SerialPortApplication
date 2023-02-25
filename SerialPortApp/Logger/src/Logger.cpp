#include "Logger.h"
#include <cstdarg>
#include <cstdio>
#include <chrono>
#include <cstring>

#ifdef UDP_LOG
#include "SocketClient/SocketClientHandler.h"
SocketClientHandler UdpClientHandler("127.0.0.1", 30000);
#endif // UDP_LOG

void Logger::LOG_DEBUG(EnumComponentType componentType, const char* format, ...)
{
    char buffer[2048 + HEADER_LENGTH] = { 0 };
    buffer[0] = '0'; // For Debug
    buffer[1] = componentType + '0';
    GetTime(&buffer[2]); // + 25
    buffer[HEADER_LENGTH - 1] = ' ';
    va_list args;
    va_start(args, format);
    vsprintf(&buffer[HEADER_LENGTH], format, args);
    va_end(args);
    int length = strlen(buffer);
    buffer[length] = '\n';
    LOG(buffer);
}

void Logger::LOG_ERROR(EnumComponentType componentType, const char* format, ...)
{
    char buffer[2048 + HEADER_LENGTH] = { 0 };
    buffer[0] = '1'; // For Error
    buffer[1] = componentType + '0';
    GetTime(&buffer[2]); // + 25
    buffer[HEADER_LENGTH - 1] = ' ';
    va_list args;
    va_start(args, format);
    vsprintf(&buffer[HEADER_LENGTH], format, args);
    va_end(args);
    int length = strlen(buffer);
    buffer[length] = '\n';
    LOG(buffer);
}

void Logger::LOG_FATAL(EnumComponentType componentType, const char* format, ...)
{
    char buffer[2048 + HEADER_LENGTH] = { 0 };
    buffer[0] = '2'; // For Fatal
    buffer[1] = componentType + '0';
    GetTime(&buffer[2]); // + 25
    buffer[HEADER_LENGTH - 1] = ' ';
    va_list args;
    va_start(args, format);
    vsprintf(&buffer[HEADER_LENGTH], format, args);
    va_end(args);
    int length = strlen(buffer);
    buffer[length] = '\n';
    LOG(buffer);
}

void Logger::LOG(const char *logMessage)
{
#ifdef CONSOLE_LOG
#ifdef LINUX_SYSTEM

    if (logMessage[0] == '0')
        printf("[\033[0;32mDEBUG");
    else if(logMessage[0] == '1')
        printf("[\033[0;33mERROR");
    else if(logMessage[0] == '2')
        printf("[\033[0;31mFATAL");
    printf("\033[0;0m]");
    switch (logMessage[1])
    {
    case '0':
        printf(" SERVER: ");
        break;
    case '1':
        printf(" CLIENT: ");
        break;
    case '2':
        printf(" COMMON: ");
        break;
    default:
        break;
    }
#endif // LINUX_SYSTEM
#ifdef WINDOWS_SYSTEM

    if (logMessage[0] == '0')
        printf("[DEBUG");
    else if (logMessage[0] == '1')
        printf("[ERROR");
    else if (logMessage[0] == '2')
        printf("[FATAL");
    printf("]");
    switch (logMessage[1])
    {
    case '0':
        printf(" SERVER: ");
        break;
    case '1':
        printf(" CLIENT: ");
        break;
    case '2':
        printf(" COMMON: ");
        break;
    default:
        break;
    }
#endif // WINDOWS_SYSTEM

    const char *remainingMessage = &logMessage[2];
    printf(remainingMessage);
#endif // CONSOLE_LOG
#ifdef UDP_LOG
    UdpClientHandler.SendData(logMessage, strlen(logMessage));
#endif // UDP_LOG


}

void Logger::GetTime(char *buffer)
{
    time_t currentTime = time(0);
    tm* timeLocal = localtime(&currentTime);
    strftime(buffer, 23, "%Y:%m:%d %H:%M:%S:", timeLocal); // 23 char with millisecond
    size_t index = strlen(buffer);
    int64_t currentTimeInMiliSec = currentTime * 1000;
    auto millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    int64_t miliSec = millisec_since_epoch - currentTimeInMiliSec;
    if (miliSec > 999)
    {
        miliSec -= 1000;
    }
    if (miliSec < 10)
    {
        buffer[index] = '0';
        buffer[index+1] = '0';
        sprintf(&buffer[index+2], "%d", (int32_t)miliSec);
    }
    else if (miliSec < 100)
    {
        buffer[index] = '0';
        sprintf(&buffer[index+1], "%d", (int32_t)miliSec);
    }
    else
    {
        sprintf(&buffer[index], "%d", (int32_t)miliSec);
    }
}
