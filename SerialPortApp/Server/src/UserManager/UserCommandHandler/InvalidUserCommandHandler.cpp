#include "InvalidUserCommandHandler.h"
#include "Commands/InvalidCommand.h"
#include "Constants.h"
#include <cstdio>
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED

InvalidUserCommandHandler::InvalidUserCommandHandler(Common::IConnection *connection) :
    m_Connection { connection } { }

InvalidUserCommandHandler::~InvalidUserCommandHandler() { }

void InvalidUserCommandHandler::Handle(Common::ICommand *command, EnumUserInputType userInputType)
{
    InvalidCommand *invalidCommand = static_cast<InvalidCommand*> (command);
    uint8_t buffer[Common::Constants::MAX_COMMAND_LENGTH] = { 0 };
    Common::ByteStream byteStream(buffer);
    uint32_t length;
    if (invalidCommand->Serialize(byteStream, length))
    {
        if (m_Connection->Send((char*)buffer, length))
        {
            printf("Message Sent: ");
            byteStream.Log();
            invalidCommand->Log();
            printf("_______________________________________________\n");
        }
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Unable To Serialize Invalid Command!");
#endif // LOG_ENABLED
    }
}
