#include "Commands/SecondCommand.h"
#include "CRCGenerator.h"
#include <cstring>
#include <cstdio>

SecondCommand::SecondCommand() : 
        m_B{0.0f}
{
    m_Header.m_Heading = 0xCA;
    m_Header.m_CommandNo = 0xA9;
    m_Header.m_CommandLength = 9;
    m_Header.m_CommandType = COMMAND_2;
}

SecondCommand::~SecondCommand() { }

bool SecondCommand::Serialize(ByteStream &byteStream, uint32_t &length)
{
    length = 0;
    if (!SerializeWithoutCRC(byteStream, length))
        return false;

    if (!byteStream.Write2Byte(m_Header.m_Crc))
        return false;
    length += 2;

    return true;
}

bool SecondCommand::Deserialize(ByteStream &byteStream, const uint32_t &length)
{
    if (!m_Header.Deserialize(byteStream, length))
        return false;

    if (length < 10)
        return false;

    uint8_t dataA;
    if (!byteStream.ReadByte(dataA))
        return false;
    m_A.Deserialize(dataA);

    uint32_t dataB;
    if (!byteStream.Read4Byte(dataB))
        return false;
    memcpy(&m_B, &dataB, sizeof(float));

    uint16_t crc;
    if (!byteStream.Read2Byte(crc))
        return false;
    m_Header.m_Crc = crc;

    return true;
}


EnumCommandType SecondCommand::GetType()
{
    return m_Header.m_CommandType;
}


uint16_t SecondCommand::CalculateCRC()
{
    uint8_t buffer [ByteStream::BUFFER_LENGTH] = { 0 };
    ByteStream byteStream(buffer);
    uint32_t length = 0;
    SerializeWithoutCRC(byteStream, length);
    
    uint16_t crc = CRCGenerator::CalculateCRC16(buffer, m_Header.m_CommandLength + 1);
    return crc;

}

bool SecondCommand::SerializeWithoutCRC(ByteStream &byteStream, uint32_t &length)
{
    if (!m_Header.Serialize(byteStream, length))
        return false;

    uint8_t dataA;
    m_A.Serialize(dataA);
    if (!byteStream.WriteByte(dataA))
        return false;
    length++;

    uint32_t *bPtr = (uint32_t*) &m_B;
    if (!byteStream.Write4Byte(*bPtr))
        return false;
    length += 4;

    return true;
}

void SecondCommand::Log()
{
    m_Header.Log();
    printf("  State A:\n");
    printf("    SingleError:  %d\n", m_A.m_SingleError);
    printf("    MessageError: %d\n", m_A.m_MessageError);
    printf("    SignalStateA: %d\n", m_A.m_SignalStateA);
    printf("    SignalStateC: %d\n", m_A.m_SignalStateC);
    printf("    DoubleError:  %d\n", m_A.m_DoubleError);
    printf("    LoadState:    %d\n", m_A.m_LoadState);
    printf("  State B:\n");
    printf("    Value: %f\n", m_B);
    printf("  CRC: 0x%04X\n", m_Header.m_Crc);
}

void SecondCommand::Reset()
{
    m_Header.Reset();
    m_Header.m_Heading = 0xCA;
    m_Header.m_CommandNo = 0xA9;
    m_Header.m_CommandLength = 9;
    m_Header.m_CommandType = COMMAND_2;
    m_A.Reset();
    m_B = 0;
}