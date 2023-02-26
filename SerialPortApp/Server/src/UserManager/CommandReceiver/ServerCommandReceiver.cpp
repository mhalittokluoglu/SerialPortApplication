#include "ServerCommandReceiver.h"
#include <cstring>
#include "CommandReader/CommandReaderFactory.h"

ServerCommandReceiver::ServerCommandReceiver() :
    m_CurrentIndex { 0 }
{
    ICommandReader *commandReader = CommandReaderFactory::CreateCommandReader();
    for (int i = 0; i< Specs::MAX_MESSAGE_IN_FILE;i++)
    {
        memset(m_Commands[i], 0, sizeof(m_Commands[i]));
    }
    commandReader->ReadFromFile("ServerCommands/Commands.csv",(uint8_t *) m_Commands, m_Length);
}

bool ServerCommandReceiver::Read(uint8_t *buffer)
{
    bool bResult = false;
    if (m_CurrentIndex < m_Length)
    {
        bResult = true;
        memcpy(buffer, &m_Commands[m_CurrentIndex], ByteStream::BUFFER_LENGTH);
        m_CurrentIndex++;
    }

    return bResult;
}


