#ifndef _INVALIDUSERCOMMANDHANDLER_H_
#define _INVALIDUSERCOMMANDHANDLER_H_
#include "IUserCommandHandler.h"
#include "SerialConfiguration/ISerialConnection.h"

class InvalidUserCommandHandler : public IUserCommandHandler
{
public:
    InvalidUserCommandHandler(ISerialConnection *connection);
    ~InvalidUserCommandHandler();
    void Handle(ICommand *command, EnumUserInputType userInputType);

private:
    ISerialConnection *m_SerialConnection;
};
#endif // _INVALIDUSERCOMMANDHANDLER_H_