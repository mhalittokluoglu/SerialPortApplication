#ifndef _STREAM_H_
#define _STREAM_H_
#include <inttypes.h>
namespace Common
{
    class ByteStream
    {
    public:
        ByteStream(uint8_t *buffer);
        bool WriteByte(const uint8_t &bufferToWrite);
        bool Write2Byte(const uint16_t &bufferToWrite);
        bool Write4Byte(const uint32_t &bufferToWrite);
        bool Write8Byte(const uint64_t &bufferToWrite);
        bool ReadByte(uint8_t &bufferToRead);
        bool Read2Byte(uint16_t &bufferToRead);
        bool Read4Byte(uint32_t &bufferToRead);
        bool Read8Byte(uint64_t &bufferToRead);
        inline void GetBuffer(void *buffer) { buffer = m_Buffer; }
        void Log();

    private:
        uint8_t *m_Buffer;
        uint8_t m_CurrentByteIndex;
    };
} // Common
#endif // _STREAM_H_