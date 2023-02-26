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
    bool Serialize(ByteStream &byteStream, int &length);
    bool Deserialize(ByteStream &byteStream, const int &length);
    CommandHeader* GetHeader();
    uint16_t CalculateCRC();
    void Log();
    void Reset();

public:
    DataA m_A;
    float m_B;
    CommandHeader m_Header;

private:
    bool SerializeWithoutCRC(ByteStream &byteStream, int &length);

};
#endif // _FIRSTCOMMAND_H_