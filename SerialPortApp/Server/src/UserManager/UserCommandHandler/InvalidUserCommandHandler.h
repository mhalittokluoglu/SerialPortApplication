#ifndef _INVALIDUSERCOMMANDHANDLER_H_
#define _INVALIDUSERCOMMANDHANDLER_H_
#include "IUserCommandHandler.h"
#include "IConnection.h"

class InvalidUserCommandHandler : public IUserCommandHandler
{
public:
    InvalidUserCommandHandler(Common::IConnection *connection);
    ~InvalidUserCommandHandler();
    void Handle(Common::ICommand *command, EnumUserInputType userInputType);

private:
    Common::IConnection *m_Connection;
};
#endif // _INVALIDUSERCOMMANDHANDLER_H_