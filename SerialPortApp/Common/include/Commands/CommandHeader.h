#ifndef _COMMANDHEADER_H_
#define _COMMANDHEADER_H_
#include "Commands/ByteStream.h"
#include "DataElements.h"
namespace Common
{
    struct CommandHeader
    {
        CommandHeader();
        virtual ~CommandHeader() {}
        virtual bool Serialize(ByteStream &byteStream, uint32_t &length);
        virtual bool Deserialize(ByteStream &byteStream, const uint32_t &length);

        inline EnumCommandType GetCommandType();

        void Log();
        void Reset();

        EnumCommandType m_CommandType;
        uint8_t m_Heading;
        uint8_t m_CommandNo;
        uint8_t m_CommandLength;
        uint16_t m_Crc;
    };
}
#endif // _COMMANDHEADER_H_