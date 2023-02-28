#ifndef _COMMANDPROCESSORFACADE_H_
#define _COMMANDPROCESSORFACADE_H_
#include "Commands/IDeserializableCommand.h"
#include "Commands/ICommandProcessor.h"
#include "Constants.h"

namespace Common
{
    class CommandProcessorFacade
    {
    public:
        virtual void Process(uint8_t *buffer, const uint32_t &length);

    protected:
        CommandProcessorFacade();
        virtual ~CommandProcessorFacade();
        IDeserializableCommand *m_Commands[Constants::MAX_COMMAND_TYPE];
        ICommandProcessor *m_Processors[Constants::MAX_COMMAND_TYPE];

    private:
        void LogBufferToConsole(uint8_t *buffer, const uint32_t length);
    };
}
#endif // _COMMANDPROCESSORFACADE_H_