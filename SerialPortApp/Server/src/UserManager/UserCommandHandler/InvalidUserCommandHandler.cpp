#include "InvalidUserCommandHandler.h"
#include "Commands/InvalidCommand.h"
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED

InvalidUserCommandHandler::InvalidUserCommandHandler(ISerialConnection *connection) :
    m_SerialConnection { connection } { }

InvalidUserCommandHandler::~InvalidUserCommandHandler() { }

void InvalidUserCommandHandler::Handle(ICommand *command, EnumUserInputType userInputType)
{
    InvalidCommand *invalidCommand = static_cast<InvalidCommand*> (command);
    uint8_t buffer[ByteStream::BUFFER_LENGTH] = { 0 };
    ByteStream byteStream(buffer);
    int length;
    if (invalidCommand->Serialize(byteStream, length))
    {
        m_SerialConnection->Send((char*)buffer, length);
    }
    else
    {
#ifdef LOG_ENABLED
        Logger::LOG_ERROR(COMPONENT_SERVER, "Unable To Serialize Invalid Command!");
#endif // LOG_ENABLED
    }
}
