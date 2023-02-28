#include "ResponseCommandProcessor.h"
#include <cstdio>

ResponseCommandProcessor::ResponseCommandProcessor() { }

ResponseCommandProcessor::~ResponseCommandProcessor() { }

void ResponseCommandProcessor::Process(ICommand *command)
{
    EnumCommandType commandType = command->GetType();
    LogCommandType(commandType);
    command->Log();
    printf("_______________________________________________\n");
}

void ResponseCommandProcessor::LogCommandType(EnumCommandType commandType)
{
    switch (commandType)
    {
    case COMMAND_2:
        printf("  Type: SecondCommand\n");
        break;
    case INVALID_REQUEST_COMMAND:
        printf("  Type: InvalidRequestCommand\n");
        break;
    
    default:
        break;
    }
}
