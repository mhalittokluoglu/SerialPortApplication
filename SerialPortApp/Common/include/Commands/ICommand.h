#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
#include <inttypes.h>
#include "CommandHeader.h"
#include "DataElements.h"
class ICommand
{
public:
    ~ICommand() { }
    virtual bool Serialize(ByteStream &byteStream, uint32_t &length) = 0;
    virtual bool Deserialize(ByteStream &byteStream, const uint32_t &length) = 0;
    virtual EnumCommandType GetType() = 0;
    virtual void Log() = 0;
    virtual void Reset() = 0;
};
#endif // _ICOMMAND_H_