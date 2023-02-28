#include "ServerProcessorFacade.h"
#include "Commands/DataElements.h"

#include "Commands/SecondCommand.h"
#include "Commands/InvalidRequestCommand.h"

#include "Processors/ResponseCommandProcessor.h"
#include <cstring>

using namespace Common;

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
