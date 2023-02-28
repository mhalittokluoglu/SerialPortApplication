#ifndef _SECONDCOMMAND_H_
#define _SECONDCOMMAND_H_
#include "Commands/ISerializableCommand.h"
#include "Commands/CommandHeader.h"
#include "Commands/Data/DataA.h"

class SecondCommand : public Common::ISerializableCommand
{
public:
    SecondCommand();
    ~SecondCommand();
    bool Serialize(Common::ByteStream &byteStream, uint32_t &length);
    Common::EnumCommandType GetType();
    uint16_t CalculateCRC();
    void Log();
    void Reset();

public:
    Common::DataA m_A;
    float m_B;
    Common::CommandHeader m_Header;

private:
    bool SerializeWithoutCRC(Common::ByteStream &byteStream, uint32_t &length);
};
#endif // _SECONDCOMMAND_H_