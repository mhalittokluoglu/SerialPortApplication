#ifndef _FIRSTCOMMANDPROCESSOR_H_
#define _FIRSTCOMMANDPROCESSOR_H_
#include "Commands/ICommandProcessor.h"
#include "Commands/Data/DataA.h"

class FirstCommandProcessor : public Common::ICommandProcessor
{
public:
    FirstCommandProcessor();
    ~FirstCommandProcessor();
    void Process(Common::ICommand *command);

private:
    void ReverseDataA(const Common::DataA &incomingDataA, Common::DataA &outDataA);
};

#endif // _FIRSTCOMMANDPROCESSOR_H_