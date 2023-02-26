#ifndef _COMMANDRECEIVERFACTORY_H_
#define _COMMANDRECEIVERFACTORY_H_
#include "ICommandReceiver.h"

class CommandReceiverFactory
{
public:
    static ICommandReceiver *CreateCommandReceiver();
};

#endif // _COMMANDRECEIVERFACTORY_H_