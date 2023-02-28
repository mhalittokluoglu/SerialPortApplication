#include "ResponseCommandProcessor.h"
#include <cstdio>

ResponseCommandProcessor::ResponseCommandProcessor() { }

ResponseCommandProcessor::~ResponseCommandProcessor() { }

void ResponseCommandProcessor::Process(Common::ICommand *command)
{
    Common::EnumCommandType commandType = command->GetType();
    LogCommandType(commandType);
    command->Log();
    printf("_______________________________________________\n");
}

void ResponseCommandProcessor::LogCommandType(Common::EnumCommandType commandType)
{
    switch (commandType)
    {
    case Common::COMMAND_2:
        printf("  Type: SecondCommand\n");
        break;
    case Common::INVALID_REQUEST_COMMAND:
        printf("  Type: InvalidRequestCommand\n");
        break;
    
    default:
        break;
    }
}
