#include "ServerCommandReceiver.h"
#include <cstring>
#include "CommandReader/CommandReaderFactory.h"
#include <cstdio>
#include "EndianController.h"

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
        LogBufferToConsole(buffer);
    }
    else if (m_CurrentIndex == m_Length)
    {
        printf("All Messages Have Been Sent!\n");
    }


    return bResult;
}


void ServerCommandReceiver::LogBufferToConsole(uint8_t *buffer)
{
    int length = buffer[1] - 1; // +1 Heading -2 CRC
    printf("ServerCommandReceiver::Buffer");
    if(!EndianController::Instance()->IsBigEndian())
        printf("(Little Endian)");
    printf(": ");

    for(int i = 0; i < length; i++)
    {
        printf("%02X", buffer[i]);
    }
    printf(" ");
}
