#ifndef _INVALIDCOMMAND_H_
#define _INVALIDCOMMAND_H_
#include "ICommand.h"
#include "DataElements.h"

class InvalidCommand : public ICommand
{
public:
    InvalidCommand();
    ~InvalidCommand();
    bool Serialize(ByteStream &byteStream, int &length);
    bool Deserialize(ByteStream &byteStream, const int &length);
    CommandHeader* GetHeader();
    void Log();
    void Reset();

public:
    CommandHeader m_Header;
    char m_Data[CommonSpecs::MAX_USER_INPUT];
};

#endif // _INVALIDCOMMAND_H_