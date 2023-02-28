#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
#include <inttypes.h>
#include "DataElements.h"
#include "ByteStream.h"

namespace Common
{
    class ICommand
    {
    public:
        virtual ~ICommand() {}
        virtual EnumCommandType GetType() = 0;
        virtual void Log() = 0;
        virtual void Reset() = 0;
    };
} // Common
#endif // _ICOMMAND_H_