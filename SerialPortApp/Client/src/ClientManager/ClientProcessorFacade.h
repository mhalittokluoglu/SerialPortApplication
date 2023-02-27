#ifndef _CLIENTPROCESSORFACADE_H_
#define _CLIENTPROCESSORFACADE_H_
#include "Commands/ICommand.h"
#include "Commands/DataElements.h"
#include "Commands/ICommandProcessor.h"

class ClientProcessorFacade
{
public:
    ClientProcessorFacade();
    ~ClientProcessorFacade();
    void Process(uint8_t *buffer, const uint32_t &length);

private:
    ICommand *m_Commands[CommonSpecs::MAX_COMMAND_TYPE];
    ICommandProcessor *m_Processors[CommonSpecs::MAX_COMMAND_TYPE];

private:
    void LogBufferToConsole(uint8_t *buffer, const uint32_t length);
};
#endif // _CLIENTPROCESSORFACADE_H_