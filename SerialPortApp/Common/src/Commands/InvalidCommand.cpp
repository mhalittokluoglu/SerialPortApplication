#include "Commands/InvalidCommand.h"
#include <cstdio>
#include <cstring>

InvalidCommand::InvalidCommand() :
    m_Data { 0 }
{
    m_Header.m_CommandType = INVALID_COMMAND;
}

InvalidCommand::~InvalidCommand() { }

bool InvalidCommand::Serialize(ByteStream &byteStream, int &length)
{
    length = 0;
    if (!m_Header.Serialize(byteStream, length))
        return false;

    for (int i = 0; i < CommonSpecs::MAX_USER_INPUT && m_Data[i]; i++)
    {
        if (!byteStream.WriteByte(m_Data[i]))
            return false;
        length++;
    }
    return true;

}

bool InvalidCommand::Deserialize(ByteStream &byteStream, const int &length)
{
    if (!m_Header.Deserialize(byteStream, length))
        return false;
    for (int i = 0; i < length - 3; i++)
    {
        uint8_t buffer = 0;
        if(byteStream.ReadByte(buffer))
            return false;
        m_Data[i] = (char) buffer;
    }
    return true;
}

CommandHeader* InvalidCommand::GetHeader()
{
    return &m_Header;
}

void InvalidCommand::Log()
{
    printf("  Type: Invalid Command:\n");
    m_Header.Log();
    printf("  Data:\n");
    printf("    %s\n", m_Data);
}

void InvalidCommand::Reset()
{
    m_Header.Reset();
    m_Header.m_CommandType = INVALID_COMMAND;
    memset(m_Data, 0, sizeof(m_Data));
}