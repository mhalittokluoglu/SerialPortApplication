#include "Commands/BaseCommand.h"

BaseCommand::BaseCommand() :
    m_Heading {0xCA},
    m_CommandLength {0},
    m_CommandNo {0},
    m_Crc {0} { }


bool BaseCommand::Serialize(ByteStream &byteStream)
{
    if (!byteStream.WriteByte(m_Heading))
        return false;
    if (!byteStream.WriteByte(m_CommandLength))
        return false;
    if (!byteStream.WriteByte(m_CommandNo))
        return false;
    return true;
}

bool BaseCommand::Deserialize(ByteStream &byteStream)
{
    if (!byteStream.ReadByte(m_Heading))
        return false;
    if (!byteStream.ReadByte(m_CommandLength))
        return false;
    if (!byteStream.ReadByte(m_CommandNo))
        return false;
    return true;
}
