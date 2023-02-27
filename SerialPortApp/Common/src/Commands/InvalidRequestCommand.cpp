#include "Commands/InvalidRequestCommand.h"
#include "CRCGenerator.h"
#include <cstring>
#include <cstdio>

InvalidRequestCommand::InvalidRequestCommand() :
    m_InvalidCause { NO_INVALID_CAUSE }
{
    m_Header.m_Heading = 0xCA;
    m_Header.m_CommandNo = 0xA5;
    m_Header.m_CommandLength = 5;
    m_Header.m_CommandType = INVALID_REQUEST_COMMAND;
}

InvalidRequestCommand::~InvalidRequestCommand() { }

bool InvalidRequestCommand::Serialize(ByteStream &byteStream, uint32_t &length)
{
    length = 0;
    if (!SerializeWithoutCRC(byteStream, length))
        return false;

    if (!byteStream.Write2Byte(m_Header.m_Crc))
        return false;
    length += 2;

    return true;
}

bool InvalidRequestCommand::Deserialize(ByteStream &byteStream, const uint32_t &length)
{
    if (!m_Header.Deserialize(byteStream, length))
        return false;

    if (length < 10)
        return false;

    uint8_t dataInvalidCause;
    if (!byteStream.ReadByte(dataInvalidCause));
        return false;
    m_InvalidCause = (EnumInvalidCause)dataInvalidCause;

    uint16_t crc;
    if (!byteStream.Read2Byte(crc))
        return false;
    m_Header.m_Crc = crc;

    return true;
}


EnumCommandType InvalidRequestCommand::GetType()
{
    return m_Header.m_CommandType;
}


uint16_t InvalidRequestCommand::CalculateCRC()
{
    uint8_t buffer [ByteStream::BUFFER_LENGTH] = { 0 };
    ByteStream byteStream(buffer);
    uint32_t length = 0;
    SerializeWithoutCRC(byteStream, length);
    
    uint16_t crc = CRCGenerator::CalculateCRC16(buffer, m_Header.m_CommandLength + 1);
    return crc;

}

bool InvalidRequestCommand::SerializeWithoutCRC(ByteStream &byteStream, uint32_t &length)
{
    if (!m_Header.Serialize(byteStream, length))
        return false;

    uint8_t dataInvalidCause = m_InvalidCause;
    if (!byteStream.WriteByte(dataInvalidCause))
        return false;
    length++;

    return true;
}

void InvalidRequestCommand::Log()
{
    m_Header.Log();
    printf("Invalid Cause: ");
    switch (m_InvalidCause)
    {
    case NO_INVALID_CAUSE:
        printf("NO_INVALID_CAUSE");
        break;
    case MESSAGE_WITH_CRC_ERROR:
        printf("MESSAGE_WITH_CRC_ERROR");
        break;
    case INVALID_MESSAGE:
        printf("INVALID_MESSAGE");
        break;
    
    default:
        break;
    }
    printf("\n");
    printf("  CRC: 0x%04X\n", m_Header.m_Crc);
}

void InvalidRequestCommand::Reset()
{
    m_Header.Reset();
    m_Header.m_Heading = 0xCA;
    m_Header.m_CommandNo = 0xA5;
    m_Header.m_CommandLength = 5;
    m_Header.m_CommandType = INVALID_REQUEST_COMMAND;
    m_InvalidCause = NO_INVALID_CAUSE;
}