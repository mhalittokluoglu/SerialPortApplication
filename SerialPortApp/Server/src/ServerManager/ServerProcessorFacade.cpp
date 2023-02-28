#include "ServerProcessorFacade.h"
#include "Commands/DataElements.h"
#include "Commands/ByteStream.h"
#include "Commands/SecondCommand.h"
#include "Commands/InvalidRequestCommand.h"

#include "Processors/ResponseCommandProcessor.h"

#include <cstring>
#include <cstdio>
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED

ServerProcessorFacade::ServerProcessorFacade()
{
    memset(m_Commands, 0, sizeof(m_Commands));
    m_Commands[COMMAND_2] = new SecondCommand();
    m_Commands[INVALID_REQUEST_COMMAND] = new InvalidRequestCommand();

    memset(m_Processors, 0, sizeof(m_Processors));
    m_Processors[COMMAND_2] = new ResponseCommandProcessor();
    m_Processors[INVALID_REQUEST_COMMAND] = new ResponseCommandProcessor();

}

ServerProcessorFacade::~ServerProcessorFacade() { }


void ServerProcessorFacade::Process(uint8_t *buffer, const uint32_t &length)
{
    uint8_t commandID = 0;
    if (length >= 3)
        commandID = buffer[2];
        
    EnumCommandType commandType = CommonSpecs::GetEnumTypeFromID(commandID);
    
    ByteStream byteStream(buffer);
    ICommand *command = m_Commands[commandType];
    if (command == NULL)
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "ServerProcessorFacade: CommandNo: %d not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    command->Reset();
    if (!command->Deserialize(byteStream, length))
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "ServerProcessorFacade: Unable to Deserialize Command: %02X not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    ICommandProcessor *processor = m_Processors[commandType];
    if (processor == NULL)
    {
#ifdef LOG_ENABLED
        Logger::LOG_DEBUG(COMPONENT_CLIENT, "ServerProcessorFacade: Processor for  CommandNo: %d not implemented!", commandID);
#endif // LOG_ENABLED
        return;
    }

    LogBufferToConsole(buffer, length);

    processor->Process(command);
}

void ServerProcessorFacade::LogBufferToConsole(uint8_t *buffer, const uint32_t length)
{
    printf("Received Message: ");
    for (int i = 0; i< length; i++)
    {
        printf("%02X", buffer[i]);
    }
    printf("\n");
}
