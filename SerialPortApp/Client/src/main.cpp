#ifdef LOG_ENABLED
#include "Logger.h"
#endif
#include "SerialConfiguration/SerialConnectionFactory.h"
#include "SerialConfiguration/SerialConfigReader.h"
#include "EndianController.h"
#include <cstring>
#include <cstdio>
#include "Commands/BaseCommand.h"

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
        char buffer[ByteStream::BUFFER_LENGTH] = { 0 };
        int len = sizeof(buffer);
        len = sizeof(buffer);
        if (serialConnection->Receive(buffer, len))
        {
            ByteStream byteStream((uint8_t*) buffer);
            BaseCommand receivedCommand;
            receivedCommand.Deserialize(byteStream);
            printf("Command Heading: %x\n", receivedCommand.m_Heading);
            printf("Command Length: %x\n", receivedCommand.m_CommandLength);
            printf("Command No: %x\n", receivedCommand.m_CommandNo);
        }
    }

/*
    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        len = sizeof(buffer);
        if (serialConnection->Receive(buffer, len))
        {
            printf("Message Received: %s\n", buffer);
        }
    }
*/
    return 0;
}