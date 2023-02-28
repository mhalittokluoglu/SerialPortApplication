#include "Commands/CommandProcessorFacade.h"
#include "Commands/CommandUtils.h"
#include "Commands/ByteStream.h"
#include <cstring>
#include <cstdio>
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED

using namespace Common;

CommandProcessorFacade::CommandProcessorFacade() { }

CommandProcessorFacade::~CommandProcessorFacade() { }

void CommandProcessorFacade::Process(uint8_t *buffer, const uint32_t &length)
{
    uint8_t commandID = 0;
    if (length >= 3)
        commandID = buffer[2];
        
    EnumCommandType commandType = Utils::GetEnumTypeFromID(commandID);
    
    ByteStream byteStream(buffer);
    IDeserializableCommand *command = m_Commands[commandType];
    if (command == NULL)
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "CommandProcessorFacade: CommandNo: %d not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    command->Reset();
    if (!command->Deserialize(byteStream, length))
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "CommandProcessorFacade: Unable to Deserialize Command: %02X not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    ICommandProcessor *processor = m_Processors[commandType];
    if (processor == NULL)
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "CommandProcessorFacade: Processor for  CommandNo: %d not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    LogBufferToConsole(buffer, length);

    processor->Process(command);
}

void CommandProcessorFacade::LogBufferToConsole(uint8_t *buffer, const uint32_t length)
{
    printf("Received Message: ");
    for (int i = 0; i< length; i++)
    {
        printf("%02X", buffer[i]);
    }
    printf("\n");
}
