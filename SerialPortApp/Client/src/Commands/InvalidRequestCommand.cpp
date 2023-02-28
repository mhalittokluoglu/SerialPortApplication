#include "InvalidRequestCommand.h"
#include "Constants.h"
#include "CRCGenerator.h"
#include <cstring>
#include <cstdio>


InvalidRequestCommand::InvalidRequestCommand() :
    m_InvalidCause { Common::NO_INVALID_CAUSE }
{
    m_Header.m_Heading = 0xCA;
    m_Header.m_CommandNo = 0xA5;
    m_Header.m_CommandLength = 5;
    m_Header.m_CommandType = Common::INVALID_REQUEST_COMMAND;
}

InvalidRequestCommand::~InvalidRequestCommand() { }

bool InvalidRequestCommand::Serialize(Common::ByteStream &byteStream, uint32_t &length)
{
    length = 0;
    if (!SerializeWithoutCRC(byteStream, length))
        return false;

    if (!byteStream.Write2Byte(m_Header.m_Crc))
        return false;
    length += 2;

    return true;
}

Common::EnumCommandType InvalidRequestCommand::GetType()
{
    return m_Header.m_CommandType;
}


uint16_t InvalidRequestCommand::CalculateCRC()
{
    uint8_t buffer [Common::Constants::MAX_COMMAND_LENGTH] = { 0 };
    Common::ByteStream byteStream(buffer);
    uint32_t length = 0;
    SerializeWithoutCRC(byteStream, length);
    
    uint16_t crc = Common::CRCGenerator::CalculateCRC16(buffer, m_Header.m_CommandLength + 1);
    return crc;

}

bool InvalidRequestCommand::SerializeWithoutCRC(Common::ByteStream &byteStream, uint32_t &length)
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
    case Common::NO_INVALID_CAUSE:
        printf("NO_INVALID_CAUSE");
        break;
    case Common::MESSAGE_WITH_CRC_ERROR:
        printf("MESSAGE_WITH_CRC_ERROR");
        break;
    case Common::INVALID_MESSAGE:
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
    m_Header.m_CommandType = Common::INVALID_REQUEST_COMMAND;
    m_InvalidCause = Common::NO_INVALID_CAUSE;
}