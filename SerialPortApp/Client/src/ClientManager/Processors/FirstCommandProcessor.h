#ifndef _FIRSTCOMMANDPROCESSOR_H_
#define _FIRSTCOMMANDPROCESSOR_H_
#include "Commands/ICommandProcessor.h"
#include "Commands/Data/DataA.h"

class FirstCommandProcessor : public ICommandProcessor
{
public:
    FirstCommandProcessor();
    ~FirstCommandProcessor();
    void Process(ICommand *command);

private:
    void ReverseDataA(const DataA &incomingDataA, DataA &outDataA);
};

#endif // _FIRSTCOMMANDPROCESSOR_H_