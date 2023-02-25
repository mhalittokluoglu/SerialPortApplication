#include "SerialConfiguration/SerialConfigReader.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>

SerialConfigReader::SerialConfigReader() { }

SerialConfigReader::~SerialConfigReader() { }

static const int BaudRateMap[MAX_BAUD_RATE] = {
                                                50,
                                                75,
                                                110,
                                                134,
                                                150,
                                                200,
                                                300,
                                                600,
                                                1200,
                                                1800,
                                                2400,
                                                4800,
                                                9600,
                                                19200,
                                                38400
};

bool SerialConfigReader::ReadConfiguration(const char *configurationFilePath, SerialConfiguration &configuration)
{
    bool bResult = true;
    std::ifstream configurationFile(configurationFilePath);
    char lineBuffer[1024] = { 0 };
    int deviceIndex;
    int baudRateIndex;
    int dataBitIndex;
    int parityIndex;
    int stopBitIndex;

    configurationFile.getline(lineBuffer, sizeof(lineBuffer)); // read header line
    std::istringstream headerStream(lineBuffer);

    for(int i = 0;headerStream.getline(lineBuffer, sizeof(lineBuffer), ';');i++)
    {
        if (strcmp(lineBuffer, "DEVICE") == 0)
            deviceIndex = i;
        else if (strcmp(lineBuffer, "BAUD_RATE") == 0)
            baudRateIndex = i;
        else if(strcmp(lineBuffer, "DATA_BIT") == 0)
            dataBitIndex = i;
        else if(strcmp(lineBuffer, "PARITY") == 0)
            parityIndex = i;
        else if (strcmp(lineBuffer, "STOP_BIT") == 0)
            stopBitIndex = i;
        else
        {
            bResult = false;
#ifdef LOG_ENABLED
            Logger::LOG_ERROR(COMPONENT_COMMON, "Invalid Configuration Parameter: %s", lineBuffer);
#endif
        }
        memset(lineBuffer, 0, sizeof(lineBuffer));
            
    }
    memset(lineBuffer, 0, sizeof(lineBuffer));

    configurationFile.getline(lineBuffer, sizeof(lineBuffer)); // read configuration line
    std::istringstream configStream(lineBuffer);

    bool deviceNameSpecified = false;
    for(int i = 0; configStream.getline(lineBuffer, sizeof(lineBuffer), ';'); i++)
    {
        if (deviceIndex == i)
        {
            if (ConvertDevice(lineBuffer, configuration.DEVICE, strlen(lineBuffer)))
            {
                deviceNameSpecified = true;
            }
            else
            {
                bResult = false;
            }
        }
        else if (baudRateIndex == i)
        {
            if (!ConvertBaudRate(lineBuffer, configuration.BAUD_RATE))
            {
                bResult = false;
#ifdef LOG_ENABLED
                Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to read BaudRate");
#endif
            }
        }
        else if (dataBitIndex == i)
        {
            if (!ConvertDataBit(lineBuffer, configuration.DATA_BIT))
            {
                bResult = false;
#ifdef LOG_ENABLED
                Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to read DataBit");
#endif
            }
        }
        else if (parityIndex == i)
        {
            if (!ConvertParity(lineBuffer, configuration.PARITY))
            {
                bResult = false;
#ifdef LOG_ENABLED
                Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to read Parity");
#endif
            }
        }
        else if (stopBitIndex == i)
        {
            if (!ConvertStopBit(lineBuffer, configuration.STOP_BIT))
            {
                bResult = false;
#ifdef LOG_ENABLED
                Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to read StopBit");
#endif
            }
        }

        memset(lineBuffer, 0, sizeof(lineBuffer));
    }

    if (!deviceNameSpecified)
    {
        bResult = false;
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_COMMON, "Device Name is not given!");
#endif
    }

    return bResult;
}

bool SerialConfigReader::ConvertDevice(char *buffer, char *device, int length)
{
    bool bResult = false;
    if (length >= SerialConfiguration::MAX_DEVICE_CHAR_LENGTH)
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_COMMON, "Unable to assign device name due to its length: %d whic is not less than %d", length, SerialConfiguration::MAX_DEVICE_CHAR_LENGTH);
#endif
    }
    else
    {
        bResult = true;
        memcpy(device, buffer, length);
    }
    return bResult;
}

bool SerialConfigReader::ConvertBaudRate(const char *buffer, EnumBaudRate &baudRate)
{
    bool bResult = false;
    int baudRateInt = atoi(buffer);
    for (int i = 0; i < MAX_BAUD_RATE; i++)
    {
        if (baudRateInt == BaudRateMap[i])
        {
            bResult = true;
            baudRate = (EnumBaudRate)i;
            break;
        }
    }
    return bResult;
}

bool SerialConfigReader::ConvertDataBit(const char *buffer, EnumDataBit &dataBit)
{
    bool bResult = true;
    if (strcmp(buffer, "CS5") == 0)
        dataBit = DATA_BIT_5;
    else if (strcmp(buffer, "CS6") == 0)
        dataBit = DATA_BIT_6;
    else if (strcmp(buffer, "CS7") == 0)
        dataBit = DATA_BIT_7;
    else if (strcmp(buffer, "CS8") == 0)
        dataBit = DATA_BIT_8;
    else
        bResult = false;
    return bResult;
}

bool SerialConfigReader::ConvertParity(const char *buffer, EnumParity &parity)
{
    bool bResult = true;
    if (strcmp(buffer, "PARITY_DISABLED") == 0)
        parity = PARITY_DISABLED;
    else if (strcmp(buffer, "PARITY_ENABLED") == 0)
        parity = PARITY_ENABLED;
    else
        bResult = false;
    return bResult;
}

bool SerialConfigReader::ConvertStopBit(const char *buffer, EnumStopBit &stopBit)
{
    bool bResult = true;
    if (strcmp(buffer, "ONE_STOP_BIT") == 0)
        stopBit = ONE_STOP_BIT;
    else if (strcmp(buffer, "TWO_STOP_BIT") == 0)
        stopBit = TWO_STOP_BIT;
    else
        bResult = false;
    return bResult;
}
