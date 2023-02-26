#ifndef _IUSERRECEIVER_H_
#define _IUSERRECEIVER_H_
#include "UserManager/UserInputType.h"

class IUserReceiver
{
public:
    virtual ~IUserReceiver() { }
    virtual EnumUserInputType GetUserInput(char *userInput) = 0;

};
#endif // _IUSERRECEIVER_H_