#ifndef _CLIENTMANAGER_H_
#define _CLIENTMANAGER_H_
#include "IManager.h"
#include "CommandManager.h"
class ClientManager : public Common::CommandManager
{
public:
    ClientManager(Common::IConnection *connection);
    ~ClientManager();
};
#endif // _CLIENTMANAGER_H_