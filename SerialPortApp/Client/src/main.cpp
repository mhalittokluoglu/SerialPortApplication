#ifdef LOG_ENABLED
#include "Logger.h"
#endif
#include "SerialConnectionFactory.h"
#include "SerialConfigReader.h"
#include "EndianController.h"
#include <cstring>
#include <cstdio>

int main()
{

    if (EndianController::Instance()->IsBigEndian())
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "System is Big Endian!");
#endif
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "System is Little Endian!");
#endif
    }


    char buffer[255] = { 0 };
    int len = sizeof(buffer);
    ISerialConnection* serialConnection = SerialConnectionFactory::CreateSerialConnection();
    SerialConfiguration serialConfiguration;
    SerialConfigReader reader;
    if (!reader.ReadConfiguration("Configuration/PortConfigurationClient.csv", serialConfiguration))
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_CLIENT, "Configuration is not valid!");
#endif
    }


    if (!serialConnection->Initialize(serialConfiguration, 0,0))
    {
#ifdef LOG_ENABLED
        Logger::LOG_FATAL(COMPONENT_CLIENT, "Serial Port Initilization Failed!");
#endif
    }

#ifdef LOG_ENABLED
    Logger::LOG_DEBUG(COMPONENT_CLIENT, "Initialization Completed. Ready to Receive!");
#endif

    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        len = sizeof(buffer);
        if (serialConnection->Receive(buffer, len))
        {
            printf("Message Received: %s\n", buffer);
        }
    }
}