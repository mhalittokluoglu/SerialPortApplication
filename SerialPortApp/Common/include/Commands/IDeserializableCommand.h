#ifndef _COMMON_IDESERIALIZABLECOMMAND_H_
#define _COMMON_IDESERIALIZABLECOMMAND_H_
#include "ICommand.h"

namespace Common
{
    class IDeserializableCommand : public ICommand
    {
    public:
        virtual ~IDeserializableCommand() { }
        virtual bool Deserialize(ByteStream &byteStream, const uint32_t &length) = 0;
    };

}
#endif // _COMMON_IDESERIALIZABLECOMMAND_H_