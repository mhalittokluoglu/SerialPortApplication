#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
#include <inttypes.h>
#include "ByteStream.h"
class ICommand
{
public:
    ~ICommand() { }
    virtual bool Serialize(ByteStream &byteStream) = 0;
    virtual bool Deserialize(ByteStream &byteStream) = 0;
};
#endif // _ICOMMAND_H_