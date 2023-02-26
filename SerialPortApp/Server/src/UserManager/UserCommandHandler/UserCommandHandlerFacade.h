#ifndef _USERCOMMANDHANDLERFACADE_H_
#define _USERCOMMANDHANDLERFACADE_H_
#include "IUserCommandHandler.h"
#include "UserCommandConverter/IUserCommandConverter.h"
#include "Commands/DataElements.h"
#include "UserManager/UserInputType.h"
#include "SerialConfiguration/ISerialConnection.h"

class UserCommandHandlerFacade
{
public:
    UserCommandHandlerFacade(ISerialConnection *connection);
    ~UserCommandHandlerFacade();
    void Handle(char *userInputBuffer, uint8_t *readedBuffer, EnumUserInputType inputType);

private:
    IUserCommandHandler *m_UserCommandHandlers[CommonSpecs::MAX_COMMAND_TYPE];
    IUserCommandConverter *m_UserCommandConverters[CommonSpecs::MAX_COMMAND_TYPE];
    ICommand *m_Commands[CommonSpecs::MAX_COMMAND_TYPE];
    
};
#endif // _USERCOMMANDHANDLERFACADE_H_