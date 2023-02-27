#include "ClientManager.h"
#include "Commands/ByteStream.h"
#include "ClientUtils/ClientUtils.h"
#
ClientManager::ClientManager(ISerialConnection *connection) :
    m_SerialConnection (connection)
{
    ClientUtils::Initialize(connection);
}

ClientManager::~ClientManager() { }

void ClientManager::Run()
{
    uint8_t buffer[ByteStream::BUFFER_LENGTH] = { 0 };
    int length = sizeof(buffer);
    if (m_SerialConnection->Receive((char*)buffer, length))
    {
        m_Facade.Process(buffer, length);
    }

}