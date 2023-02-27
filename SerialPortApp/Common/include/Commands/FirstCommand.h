#ifndef _FIRSTCOMMAND_H_
#define _FIRSTCOMMAND_H_
#include "ICommand.h"
#include "CommandHeader.h"
#include "Data/DataA.h"

class FirstCommand : public ICommand
{
public:
    FirstCommand();
    ~FirstCommand();
    bool Serialize(ByteStream &byteStream, uint32_t &length);
    bool Deserialize(ByteStream &byteStream, const uint32_t &length);
    EnumCommandType GetType();
    uint16_t CalculateCRC();
    void Log();
    void Reset();

public:
    DataA m_A;
    float m_B;
    CommandHeader m_Header;

private:
    bool SerializeWithoutCRC(ByteStream &byteStream, uint32_t &length);

};
#endif // _FIRSTCOMMAND_H_