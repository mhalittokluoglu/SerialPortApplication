#include "ServerManager.h"
#include "Commands/ByteStream.h"
ServerManager::ServerManager(ISerialConnection *connection) :
    m_SerialConnection (connection)
{
}

ServerManager::~ServerManager() { }

void ServerManager::Run()
{
    uint8_t buffer[ByteStream::BUFFER_LENGTH] = { 0 };
    int length = sizeof(buffer);
    
    if (m_SerialConnection->Receive((char*)buffer, length))
    {
        m_Facade.Process(buffer, length);
    }
}