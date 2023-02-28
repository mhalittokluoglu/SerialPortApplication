#ifndef _INVALIDCOMMANDPROCESSOR_H_
#define _INVALIDCOMMANDPROCESSOR_H_
#include "Commands/ICommandProcessor.h"

class InvalidCommandProcessor : public Common::ICommandProcessor
{
public:
    InvalidCommandProcessor();
    ~InvalidCommandProcessor();
    void Process(Common::ICommand *command);
};

#endif // _INVALIDCOMMANDPROCESSOR_H_