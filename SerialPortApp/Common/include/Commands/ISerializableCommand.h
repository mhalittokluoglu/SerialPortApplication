#ifndef _COMMON_ISERIALIZABLECOMMAND_H_
#define _COMMON_ISERIALIZABLECOMMAND_H_
#include "ICommand.h"

namespace Common
{
    class ISerializableCommand : public ICommand
    {
    public:
        virtual ~ISerializableCommand() { }
        virtual bool Serialize(ByteStream &byteStream, uint32_t &length) = 0;
    };

}
#endif // _COMMON_ISERIALIZABLECOMMAND_H_