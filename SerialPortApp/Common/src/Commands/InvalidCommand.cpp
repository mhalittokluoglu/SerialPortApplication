#include "Commands/InvalidCommand.h"
#include <cstdio>
#include <cstring>

InvalidCommand::InvalidCommand() :
    m_Data { 0 }, m_CommandType { INVALID_COMMAND }
{
}

InvalidCommand::~InvalidCommand() { }

bool InvalidCommand::Serialize(ByteStream &byteStream, uint32_t &length)
{
    length = 0;
    for (int i = 0; i < CommonSpecs::MAX_USER_INPUT && m_Data[i]; i++)
    {
        if (!byteStream.WriteByte(m_Data[i]))
            return false;
        length++;
    }
    return true;
}

bool InvalidCommand::Deserialize(ByteStream &byteStream, const uint32_t &length)
{
    for (int i = 0; i < length; i++)
    {
        uint8_t buffer = 0;
        if(!byteStream.ReadByte(buffer))
            return false;
        m_Data[i] = (char) buffer;
    }
    return true;
}

EnumCommandType InvalidCommand::GetType()
{
    return m_CommandType;
}

void InvalidCommand::Log()
{
    printf("  Data: %s\n", m_Data);
}

void InvalidCommand::Reset()
{
    m_CommandType = INVALID_COMMAND;
    memset(m_Data, 0, sizeof(m_Data));
}