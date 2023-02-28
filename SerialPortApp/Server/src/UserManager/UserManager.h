#ifndef _USERMANAGER_H_
#define _USERMANAGER_H_
#include "IManager.h"
#include "ApplicationState.h"
#include "CommandReceiver/ICommandReceiver.h"
#include "UserReceiver/IUserReceiver.h"
#include "UserCommandHandler/UserCommandHandlerFacade.h"

class UserManager : public Common::IManager
{
public:
    UserManager(ApplicationState *state, Common::IConnection *connection);
    ~UserManager();
    void Run();
private:
    ApplicationState *m_State;
    ICommandReceiver *m_CommandReceiver;
    IUserReceiver *m_UserReceiver;
    UserCommandHandlerFacade *m_UserCommandHandlerFacade;

};
#endif // _USERMANAGER_H_
