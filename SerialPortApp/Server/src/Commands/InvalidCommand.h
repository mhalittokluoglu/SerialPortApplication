#ifndef _INVALIDCOMMAND_H_
#define _INVALIDCOMMAND_H_
#include "Commands/ISerializableCommand.h"
#include "Commands/DataElements.h"
#include "Constants.h"

class InvalidCommand : public Common::ISerializableCommand
{
public:
    InvalidCommand();
    ~InvalidCommand();
    bool Serialize(Common::ByteStream &byteStream, uint32_t &length);
    Common::EnumCommandType GetType();
    void Log();
    void Reset();

public:
    Common::EnumCommandType m_CommandType;
    char m_Data[Common::Constants::MAX_COMMAND_LENGTH];
};

#endif // _INVALIDCOMMAND_H_