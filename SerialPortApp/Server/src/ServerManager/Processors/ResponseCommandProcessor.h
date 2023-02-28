#ifndef _RESPONSECOMMANDPROCESSOR_H_
#define _RESPONSECOMMANDPROCESSOR_H_
#include "Commands/ICommandProcessor.h"
#include "Commands/Data/DataA.h"

class ResponseCommandProcessor : public Common::ICommandProcessor
{
public:
    ResponseCommandProcessor();
    ~ResponseCommandProcessor();
    void Process(Common::ICommand *command);

private:
    void LogCommandType(Common::EnumCommandType commandType);
};

#endif // _RESPONSECOMMANDPROCESSOR_H_