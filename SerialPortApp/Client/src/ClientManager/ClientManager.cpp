#include "ClientManager.h"
#include "Commands/ByteStream.h"
#include "ClientUtils/ClientUtils.h"
#include "ClientProcessorFacade.h"

using namespace Common;

ClientManager::ClientManager(IConnection *connection) : 
    CommandManager(connection)
{
    ClientUtils::Initialize(connection);
    m_Facade = new ClientProcessorFacade();
}

ClientManager::~ClientManager() { }
