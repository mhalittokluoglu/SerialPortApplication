#include "Commands/CommandHeader.h"
#include <cstdio>

CommandHeader::CommandHeader()
{
    Reset();
}


bool CommandHeader::Serialize(ByteStream &byteStream, int &length)
{
    if (!byteStream.WriteByte(m_Heading))
        return false;
    length++;
    if (!byteStream.WriteByte(m_CommandLength))
        return false;
    length++;
    if (!byteStream.WriteByte(m_CommandNo))
        return false;
    length++;
    return true;
}

bool CommandHeader::Deserialize(ByteStream &byteStream, const int &length)
{
    if (length < 3)
        return 0;
    if (!byteStream.ReadByte(m_Heading))
        return false;
    if (!byteStream.ReadByte(m_CommandLength))
        return false;
    if (!byteStream.ReadByte(m_CommandNo))
        return false;
    return true;
}

void CommandHeader::Log()
{
    printf("  Header:\n");
    printf("    Heading: %02X\n", m_Heading);
    printf("    Length: %d\n", m_CommandLength);
    printf("    Command No: %02X\n", m_CommandNo);
}

void CommandHeader::Reset()
{
    m_Heading = 0;
    m_CommandLength = 0;
    m_CommandNo = 0;
    m_CommandType = INVALID_COMMAND;
    m_Crc = 0;
}