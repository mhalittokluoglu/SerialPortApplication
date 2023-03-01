#include "UserFirstCommandHandler.h"
#include "Commands/FirstCommand.h"
#include "Constants.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED
#include <cstdio>

UserFirstCommandHandler::UserFirstCommandHandler(Common::IConnection *connection) :
    m_Connection { connection } { }

UserFirstCommandHandler::~UserFirstCommandHandler() { }

void UserFirstCommandHandler::Handle(Common::ICommand *command, EnumUserInputType userInputType)
{
    FirstCommand *command1 = static_cast<FirstCommand*> (command);
    uint8_t buffer[Common::Constants::MAX_COMMAND_LENGTH] = { 0 };
    Common::ByteStream byteStream(buffer);
    uint32_t length;
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
        if (m_Connection->Send((char*)buffer, length))
        {
            printf("Message Sent: ");
            byteStream.Log();
            command1->Log();
            printf("_______________________________________________\n");
        }
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Unable To Serialize Command1!");
#endif // LOG_ENABLED
    }
}
