#ifndef _SECONDCOMMAND_H_
#define _SECONDCOMMAND_H_
#include "Commands/IDeserializableCommand.h"
#include "Commands/CommandHeader.h"
#include "Commands/Data/DataA.h"

class SecondCommand : public Common::IDeserializableCommand
{
public:
    SecondCommand();
    ~SecondCommand();
    bool Deserialize(Common::ByteStream &byteStream, const uint32_t &length);
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