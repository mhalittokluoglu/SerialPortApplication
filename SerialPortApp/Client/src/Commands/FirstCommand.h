#ifndef _FIRSTCOMMAND_H_
#define _FIRSTCOMMAND_H_
#include "Commands/IDeserializableCommand.h"
#include "Commands/CommandHeader.h"
#include "Commands/Data/DataA.h"

class FirstCommand : public Common::IDeserializableCommand
{
public:
    FirstCommand();
    ~FirstCommand();
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
#endif // _FIRSTCOMMAND_H_