#ifndef _INVALIDCOMMAND_H_
#define _INVALIDCOMMAND_H_
#include "Commands/IDeserializableCommand.h"
#include "Commands/DataElements.h"
#include "Constants.h"

class InvalidCommand : public Common::IDeserializableCommand
{
public:
    InvalidCommand();
    ~InvalidCommand();
    bool Deserialize(Common::ByteStream &byteStream, const uint32_t &length);
    Common::EnumCommandType GetType();
    void Log();
    void Reset();

public:
    Common::EnumCommandType m_CommandType;
    char m_Data[Common::Constants::MAX_COMMAND_LENGTH];
};

#endif // _INVALIDCOMMAND_H_