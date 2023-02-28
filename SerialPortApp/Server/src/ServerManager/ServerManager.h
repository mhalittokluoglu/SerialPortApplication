#ifndef _SERVERMANAGER_H_
#define _SERVERMANAGER_H_
#include "IConnection.h"
#include "CommandManager.h"

class ServerManager : public Common::CommandManager
{
public:
    ServerManager(Common::IConnection *connection);
    ~ServerManager();
};
#endif // _SERVERMANAGER_H_