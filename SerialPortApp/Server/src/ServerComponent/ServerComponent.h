#ifndef _SERVERCOMPONENT_H_
#define _SERVERCOMPONENT_H_
#include "ApplicationState.h"
#include "UserManager/UserManager.h"

class ServerComponent
{
public:
    ServerComponent();
    ~ServerComponent();
    void RunApplication();

private:
    ApplicationState m_State;
    UserManager *m_UserManager;
};
#endif // _SERVERCOMPONENT_H_