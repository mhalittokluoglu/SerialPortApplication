#ifndef _INVALIDREQUESTCOMMAND_H_
#define _INVALIDREQUESTCOMMAND_H_
#include "Commands/ISerializableCommand.h"
#include "Commands/CommandHeader.h"
#include "Commands/DataElements.h"

class InvalidRequestCommand : public Common::ISerializableCommand
{
public:
    InvalidRequestCommand();
    ~InvalidRequestCommand();
    bool Serialize(Common::ByteStream &byteStream, uint32_t &length);
    Common::EnumCommandType GetType();
    uint16_t CalculateCRC();
    void Log();
    void Reset();

public:
    Common::EnumInvalidCause m_InvalidCause;
    Common::CommandHeader m_Header;

private:
    bool SerializeWithoutCRC(Common::ByteStream &byteStream, uint32_t &length);
};
#endif // _INVALIDREQUESTCOMMAND_H_