#include "InvalidCommand.h"
#include "Constants.h"
#include <cstdio>
#include <cstring>

InvalidCommand::InvalidCommand() :
    m_Data { 0 }, m_CommandType { Common::INVALID_COMMAND }
{
}

InvalidCommand::~InvalidCommand() { }

bool InvalidCommand::Serialize(Common::ByteStream &byteStream, uint32_t &length)
{
    length = 0;
    for (int i = 0; i < Common::Constants::MAX_COMMAND_LENGTH && m_Data[i]; i++)
    {
        if (!byteStream.WriteByte(m_Data[i]))
            return false;
        length++;
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