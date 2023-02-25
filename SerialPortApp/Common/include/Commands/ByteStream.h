#ifndef _STREAM_H_
#define _STREAM_H_
#include <inttypes.h>
class ByteStream
{
public:
    ByteStream(uint8_t* buffer);
    bool WriteByte(const uint8_t &bufferToWrite);
    bool Write2Byte(const uint16_t &bufferToWrite);
    bool Write4Byte(const uint32_t &bufferToWrite);
    bool Write8Byte(const uint64_t &bufferToWrite);
    bool ReadByte(uint8_t &bufferToRead);
    bool Read2Byte(uint16_t &bufferToRead);
    bool Read4Byte(uint32_t &bufferToRead);
    bool Read8Byte(uint64_t &bufferToRead);
    static const uint32_t BUFFER_LENGTH = 255;

private:
    uint8_t *m_Buffer;
    uint8_t m_CurrentByteIndex;

};
#endif // _STREAM_H_