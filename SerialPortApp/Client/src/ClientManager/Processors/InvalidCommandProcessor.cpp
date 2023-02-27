#include "InvalidCommandProcessor.h"
#include "Commands/InvalidCommand.h"
#include "ClientManager/ClientUtils/ClientUtils.h"
#include <cstdio>

InvalidCommandProcessor::InvalidCommandProcessor() { }

InvalidCommandProcessor::~InvalidCommandProcessor() { }

void InvalidCommandProcessor::Process(ICommand *command)
{
    InvalidCommand *invalidCommand = static_cast<InvalidCommand*>(command);
    printf("  CommandType: Invalid Command\n");
    invalidCommand->Log();
    printf("\n");
    ClientUtils::SendInvalidRequestCommand(EnumInvalidCause::INVALID_MESSAGE);
}

