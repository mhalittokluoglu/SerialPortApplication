#ifndef _USERCOMMANDHANDLERFACADE_H_
#define _USERCOMMANDHANDLERFACADE_H_
#include "IUserCommandHandler.h"
#include "UserCommandConverter/IUserCommandConverter.h"
#include "UserManager/UserInputType.h"
#include "IConnection.h"
#include "Constants.h"

class UserCommandHandlerFacade
{
public:
    UserCommandHandlerFacade(Common::IConnection *connection);
    ~UserCommandHandlerFacade();
    void Handle(char *userInputBuffer, uint8_t *readedBuffer, EnumUserInputType inputType);

private:
    IUserCommandHandler *m_UserCommandHandlers[Common::Constants::MAX_COMMAND_TYPE];
    IUserCommandConverter *m_UserCommandConverters[Common::Constants::MAX_COMMAND_TYPE];
    Common::ICommand *m_Commands[Common::Constants::MAX_COMMAND_TYPE];
    
};
#endif // _USERCOMMANDHANDLERFACADE_H_