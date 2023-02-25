#ifdef LOG_ENABLED
#include "Logger.h"
#endif
#include "SerialConnectionFactory.h"
#include "SerialConfigReader.h"
#include "EndianController.h"
#include <cstring>
#include <cstdio>
#include <iostream>

  
int main()
{
    if (EndianController::Instance()->IsBigEndian())
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_SERVER, "System is Big Endian!");
#endif
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_SERVER, "System is Little Endian!");
#endif
    }
    ISerialConnection* serialConnection = SerialConnectionFactory::CreateSerialConnection();
    SerialConfiguration serialConfiguration;
    SerialConfigReader reader;
    if (!reader.ReadConfiguration("Configuration/PortConfigurationServer.csv", serialConfiguration))
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Configuration is not valid!");
#endif
    }

    if (!serialConnection->Initialize(serialConfiguration, 0,0))
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_SERVER, "Serial Port Initilization Failed!");
#endif
    }

    char message[255];
    while (true)
    {
        memset(message, 0, sizeof(message));
        printf("Message to Send: ");
        std::cin.getline(message, sizeof(message));
        int len = strlen(message);
        len = strlen(message);
        if (serialConnection->Send(message, len))
        {
#ifdef LOG_ENABLED
            Logger::LOG_DEBUG(COMPONENT_SERVER, "Message: %s with %d lenght sent", message, len);
#endif
        }
        else
        {
#ifdef LOG_ENABLED
            Logger::LOG_ERROR(COMPONENT_SERVER, "Could not send the message: %s", message);
#endif
        }
    }

    return 0;
}