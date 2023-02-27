#ifndef _INVALIDREQUESTCOMMAND_H_
#define _INVALIDREQUESTCOMMAND_H_
#include "ICommand.h"
#include "CommandHeader.h"
#include "DataElements.h"

class InvalidRequestCommand : public ICommand
{
public:
    InvalidRequestCommand();
    ~InvalidRequestCommand();
    bool Serialize(ByteStream &byteStream, uint32_t &length);
    bool Deserialize(ByteStream &byteStream, const uint32_t &length);
    EnumCommandType GetType();
    uint16_t CalculateCRC();
    void Log();
    void Reset();

public:
    EnumInvalidCause m_InvalidCause;
    CommandHeader m_Header;

private:
    bool SerializeWithoutCRC(ByteStream &byteStream, uint32_t &length);

};
#endif // _INVALIDREQUESTCOMMAND_H_