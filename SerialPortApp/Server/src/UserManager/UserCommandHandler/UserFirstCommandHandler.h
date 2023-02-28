#ifndef _USERFIRSTCOMMANDHANDLER_H_
#define _USERFIRSTCOMMANDHANDLER_H_
#include "IUserCommandHandler.h"
#include "IConnection.h"

class UserFirstCommandHandler : public IUserCommandHandler
{
public:
    UserFirstCommandHandler(Common::IConnection *connection);
    ~UserFirstCommandHandler();
    void Handle(Common::ICommand *command, EnumUserInputType userInputType);

private:
    Common::IConnection *m_SerialConnection;
};

#endif // _USERFIRSTCOMMANDHANDLER_H_