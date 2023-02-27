#ifndef _INVALIDCOMMAND_H_
#define _INVALIDCOMMAND_H_
#include "ICommand.h"
#include "DataElements.h"

class InvalidCommand : public ICommand
{
public:
    InvalidCommand();
    ~InvalidCommand();
    bool Serialize(ByteStream &byteStream, uint32_t &length);
    bool Deserialize(ByteStream &byteStream, const uint32_t &length);
    EnumCommandType GetType();
    void Log();
    void Reset();

public:
    EnumCommandType m_CommandType;
    char m_Data[CommonSpecs::MAX_USER_INPUT];
};

#endif // _INVALIDCOMMAND_H_