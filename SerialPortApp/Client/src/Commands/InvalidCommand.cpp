#include "InvalidCommand.h"
#include "Constants.h"
#include <cstdio>
#include <cstring>

InvalidCommand::InvalidCommand() :
    m_Data { 0 }, m_CommandType { Common::INVALID_COMMAND }
{
}

InvalidCommand::~InvalidCommand() { }

bool InvalidCommand::Deserialize(Common::ByteStream &byteStream, const uint32_t &length)
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

Common::EnumCommandType InvalidCommand::GetType()
{
    return m_CommandType;
}

void InvalidCommand::Log()
{
    printf("  Data: %s\n", m_Data);
}

void InvalidCommand::Reset()
{
    m_CommandType = Common::INVALID_COMMAND;
    memset(m_Data, 0, sizeof(m_Data));
}