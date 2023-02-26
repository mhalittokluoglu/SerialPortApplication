#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
#include <inttypes.h>
#include "CommandHeader.h"
class ICommand
{
public:
    ~ICommand() { }
    virtual bool Serialize(ByteStream &byteStream, int &length) = 0;
    virtual bool Deserialize(ByteStream &byteStream, const int &length) = 0;
    virtual CommandHeader* GetHeader() = 0;
    virtual void Log() = 0;
    virtual void Reset() = 0;
};
#endif // _ICOMMAND_H_