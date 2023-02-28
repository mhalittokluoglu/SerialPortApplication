#include "ServerManager.h"
#include "Commands/ByteStream.h"
#include "ServerProcessorFacade.h"

using namespace Common;

ServerManager::ServerManager(IConnection *connection) :
    CommandManager(connection)
{
    m_Facade = new ServerProcessorFacade();
}

ServerManager::~ServerManager() { }
