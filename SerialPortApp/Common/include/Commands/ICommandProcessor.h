#ifndef _ICOMMANDPROCESSOR_H_
#define _ICOMMANDPROCESSOR_H_
#include "ICommand.h"
class ICommandProcessor
{
public:
    virtual ~ICommandProcessor() { }
    virtual void Process(ICommand *command) = 0;
    
};
#endif // _ICOMMANDPROCESSOR_H_