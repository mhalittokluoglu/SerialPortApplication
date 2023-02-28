#include "ClientProcessorFacade.h"
#include "Commands/DataElements.h"
#include "Commands/FirstCommand.h"
#include "Commands/InvalidCommand.h"

#include "Processors/FirstCommandProcessor.h"
#include "Processors/InvalidCommandProcessor.h"

#include <cstring>

using namespace Common;

ClientProcessorFacade::ClientProcessorFacade()
{
    memset(m_Commands, 0, sizeof(m_Commands));
    m_Commands[COMMAND_1] = new FirstCommand();
    m_Commands[INVALID_COMMAND] = new InvalidCommand();

    memset(m_Processors, 0, sizeof(m_Processors));
    m_Processors[COMMAND_1] = new FirstCommandProcessor();
    m_Processors[INVALID_COMMAND] = new InvalidCommandProcessor();

}

ClientProcessorFacade::~ClientProcessorFacade() { }