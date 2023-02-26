#ifndef _USERFIRSTCOMMANDHANDLER_H_
#define _USERFIRSTCOMMANDHANDLER_H_
#include "IUserCommandHandler.h"
#include "SerialConfiguration/ISerialConnection.h"

class UserFirstCommandHandler : public IUserCommandHandler
{
public:
    UserFirstCommandHandler(ISerialConnection *connection);
    ~UserFirstCommandHandler();
    void Handle(ICommand *command, EnumUserInputType userInputType);

private:
    ISerialConnection *m_SerialConnection;
};

#endif // _USERFIRSTCOMMANDHANDLER_H_