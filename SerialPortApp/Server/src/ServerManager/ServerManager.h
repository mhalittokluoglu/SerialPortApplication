#ifndef _SERVERMANAGER_H_
#define _SERVERMANAGER_H_
#include "IManager.h"
#include "SerialConfiguration/ISerialConnection.h"
#include "ServerProcessorFacade.h"
class ServerManager : public IManager
{
public:
    ServerManager(ISerialConnection *connection);
    ~ServerManager();
    void Run();

private:
    ISerialConnection *m_SerialConnection;
    ServerProcessorFacade m_Facade;
};
#endif // _SERVERMANAGER_H_