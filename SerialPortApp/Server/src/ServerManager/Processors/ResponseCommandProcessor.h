#ifndef _RESPONSECOMMANDPROCESSOR_H_
#define _RESPONSECOMMANDPROCESSOR_H_
#include "Commands/ICommandProcessor.h"
#include "Commands/Data/DataA.h"

class ResponseCommandProcessor : public ICommandProcessor
{
public:
    ResponseCommandProcessor();
    ~ResponseCommandProcessor();
    void Process(ICommand *command);

private:
    void LogCommandType(EnumCommandType commandType);
};

#endif // _RESPONSECOMMANDPROCESSOR_H_