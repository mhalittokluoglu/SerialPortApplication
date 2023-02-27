#ifndef _CLIENTCOMPONENT_H_
#define _CLIENTCOMPONENT_H_
#include "ClientManager/ClientManager.h"
class ClientComponent
{
public:
    ClientComponent();
    ~ClientComponent();
    void RunApplication();

private:
    ClientManager* m_ClientManager;


};
#endif // _CLIENTCOMPONENT_H_