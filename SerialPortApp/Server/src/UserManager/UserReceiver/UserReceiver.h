#ifndef _USERRECEIVER_H_
#define _USERRECEIVER_H_
#include "IUserReceiver.h"

class UserReceiver : public IUserReceiver
{
public:
    UserReceiver();
    ~UserReceiver();
    EnumUserInputType GetUserInput(char *userInput);
};
#endif // _USERRECEIVER_H_