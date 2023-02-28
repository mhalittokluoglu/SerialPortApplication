#include "CommandManager.h"
#include "Commands/ByteStream.h"
#include "Constants.h"

using namespace Common;

CommandManager::CommandManager(IConnection *connection) :
    m_Connection (connection)
{
}

CommandManager::~CommandManager() { }

void CommandManager::Run()
{
    uint8_t buffer[Constants::MAX_COMMAND_LENGTH] = { 0 };
    int length = sizeof(buffer);
    if (m_Connection->Receive((char*)buffer, length))
    {
        m_Facade->Process(buffer, length);
    }
}