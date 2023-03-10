#include "Commands/ByteStream.h"
#include "EndianController.h"
#include "Constants.h"
#include <cstring>
#include <cstdio>

using namespace Common;

ByteStream::ByteStream(uint8_t* buffer) :
    m_Buffer { buffer },
    m_CurrentByteIndex { 0 }
{
}

bool ByteStream::WriteByte(const uint8_t &bufferToWrite)
{
    if (m_CurrentByteIndex > Constants::MAX_COMMAND_LENGTH - 1)
        return false;
    m_Buffer[m_CurrentByteIndex] = bufferToWrite;
    m_CurrentByteIndex++;
    return true;
}

bool ByteStream::Write2Byte(const uint16_t &bufferToWrite)
{
    if (m_CurrentByteIndex > Constants::MAX_COMMAND_LENGTH - 2)
        return false;

    const uint8_t *buffer = (const uint8_t*)&bufferToWrite;
    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&m_Buffer[m_CurrentByteIndex], buffer, 2);
    }
    else
    {
        buffer += 1;
        for (uint8_t i = 0; i < 2; i++)
        {
            memcpy(&m_Buffer[m_CurrentByteIndex + i], buffer - i, 1);
        }
    }
    m_CurrentByteIndex += 2;
    return true;
}

bool ByteStream::Write4Byte(const uint32_t &bufferToWrite)
{
    if (m_CurrentByteIndex > Constants::MAX_COMMAND_LENGTH - 4)
        return false;

    const uint8_t *buffer = (const uint8_t*)&bufferToWrite;
    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&m_Buffer[m_CurrentByteIndex], buffer, 4);
    }
    else
    {
        buffer += 3;
        for (uint8_t i = 0; i < 4; i++)
        {
            memcpy(&m_Buffer[m_CurrentByteIndex + i], buffer - i, 1);
        }
    }
    m_CurrentByteIndex += 4;
    return true;
}

bool ByteStream::Write8Byte(const uint64_t &bufferToWrite)
{
    if (m_CurrentByteIndex > Constants::MAX_COMMAND_LENGTH - 8)
        return false;

    const uint8_t *buffer = (const uint8_t*)&bufferToWrite;
    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&m_Buffer[m_CurrentByteIndex], buffer, 8);
    }
    else
    {
        buffer += 7;
        for (uint8_t i = 0; i < 8; i++)
        {
            memcpy(&m_Buffer[m_CurrentByteIndex + i], buffer - i, 1);
        }
    }
    m_CurrentByteIndex += 8;
    return true;
}


bool ByteStream::ReadByte(uint8_t &bufferToRead)
{
    if (m_CurrentByteIndex > 254) 
        return false;
    bufferToRead = m_Buffer[m_CurrentByteIndex];
    m_CurrentByteIndex++;
    return true;
}

bool ByteStream::Read2Byte(uint16_t &bufferToRead)
{
    if (m_CurrentByteIndex > 253)
        return false;
    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&bufferToRead, &m_Buffer[m_CurrentByteIndex], 2);
    }
    else
    {
        uint8_t *buffer = (uint8_t *)&bufferToRead;
        for (uint8_t i = 0; i < 2; i++)
        {
            memcpy(buffer+i, &m_Buffer[m_CurrentByteIndex + 1 - i], 1);
        }
    }
    m_CurrentByteIndex += 2;
    return true;
}

bool ByteStream::Read4Byte(uint32_t &bufferToRead)
{
    if (m_CurrentByteIndex > 251)
        return false;
    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&bufferToRead, &m_Buffer[m_CurrentByteIndex], 4);
    }
    else
    {
        uint8_t *buffer = (uint8_t *)&bufferToRead;
        for (uint8_t i = 0; i < 4; i++)
        {
            memcpy(buffer+i, &m_Buffer[m_CurrentByteIndex + 3 - i], 1);
        }
    }
    m_CurrentByteIndex += 4;
    return true;
}

bool ByteStream::Read8Byte(uint64_t &bufferToRead)
{
    if (m_CurrentByteIndex > 247)
        return false;

    if (EndianController::Instance()->IsBigEndian())
    {
        memcpy(&bufferToRead, &m_Buffer[m_CurrentByteIndex], 8);
    }
    else
    {
        uint8_t *buffer = (uint8_t *)&bufferToRead;
        for (uint8_t i = 0; i < 8; i++)
        {
            memcpy(buffer+i, &m_Buffer[m_CurrentByteIndex + 7 - i], 1);
        }
    }
    m_CurrentByteIndex += 8;
    return true;
}

void ByteStream::Log()
{
    printf("0x");
    for(int i = 0; i < m_CurrentByteIndex; i++)
        printf("%02X", m_Buffer[i]);
    printf("\n");
}