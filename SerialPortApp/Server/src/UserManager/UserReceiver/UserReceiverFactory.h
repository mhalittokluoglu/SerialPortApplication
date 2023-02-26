#ifndef _USERRECEIVERFACTORY_H_
#define _USERRECEIVERFACTORY_H_
#include "IUserReceiver.h"
class UserReceiverFactory
{
public:
    static IUserReceiver *CreateUserReceiver();
};
#endif // _USERRECEIVERFACTORY_H_