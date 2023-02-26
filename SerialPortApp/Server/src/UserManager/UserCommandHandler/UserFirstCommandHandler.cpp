#include "UserFirstCommandHandler.h"
#include "Commands/FirstCommand.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED
#include <cstdio>

UserFirstCommandHandler::UserFirstCommandHandler(ISerialConnection *connection) :
    m_SerialConnection { connection } { }

UserFirstCommandHandler::~UserFirstCommandHandler() { }

void UserFirstCommandHandler::Handle(ICommand *command, EnumUserInputType userInputType)
{
    FirstCommand *command1 = static_cast<FirstCommand*> (command);
    uint8_t buffer[ByteStream::BUFFER_LENGTH] = { 0 };
    ByteStream byteStream(buffer);
    int length;
    uint16_t crc = command1->CalculateCRC();
    if (userInputType == CRC_ER)
    {
        if (crc == 0xFFFF)
            crc = 0;
        else
            crc++;
    }
    command1->m_Header.m_Crc = crc;
    if (command1->Serialize(byteStream, length))
    {
        if (m_SerialConnection->Send((char*)buffer, length))
        {
            printf("Message Sent: ");
            byteStream.Log();
            printf("\n");
            command1->Log();
        }
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Unable To Serialize Command1!");
#endif // LOG_ENABLED
    }
}
