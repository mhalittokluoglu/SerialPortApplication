#ifndef _IUSERCOMMANDHANDLER_H_
#define _IUSERCOMMANDHANDLER_H_
#include "Commands/ICommand.h"
#include "UserManager/UserInputType.h"
class IUserCommandHandler
{
public:
    virtual ~IUserCommandHandler() { }
    virtual void Handle(Common::ICommand *command, EnumUserInputType userInputType) = 0;
};
#endif // _IUSERCOMMANDHANDLER_H_