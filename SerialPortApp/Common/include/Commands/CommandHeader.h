#ifndef _COMMANDHEADER_H_
#define _COMMANDHEADER_H_
#include "Commands/ByteStream.h"
#include "DataElements.h"
struct CommandHeader
{
    CommandHeader();
    virtual ~CommandHeader() { }
    virtual bool Serialize(ByteStream &byteStream, int &length);
    virtual bool Deserialize(ByteStream &byteStream, const int &length);

    inline uint16_t GetCRC() const { return m_Crc; }
    inline EnumCommandType GetCommandType();
    
    void Log();
    void Reset();

    EnumCommandType m_CommandType;
    uint8_t m_Heading;
    uint8_t m_CommandNo;
    uint8_t m_CommandLength;
    uint16_t m_Crc;


};
#endif // _COMMANDHEADER_H_