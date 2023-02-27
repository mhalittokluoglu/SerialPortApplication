#ifndef _CLIENTMANAGER_H_
#define _CLIENTMANAGER_H_
#include "IManager.h"
#include "SerialConfiguration/ISerialConnection.h"
#include "ClientProcessorFacade.h"
class ClientManager : public IManager
{
public:
    ClientManager(ISerialConnection *connection);
    ~ClientManager();
    void Run();

private:
    ISerialConnection *m_SerialConnection;
    ClientProcessorFacade m_Facade;
};
#endif // _CLIENTMANAGER_H_