#ifndef _COMMON_COMMONUTILS_H_
#define _COMMON_COMMONUTILS_H_
#include "Commands/DataElements.h"

namespace Common
{
    struct Utils
    {
        static const uint8_t CommandMap[MAX_COMMAND];
        static EnumCommandType GetEnumTypeFromID(uint8_t commandID);
    };
}

#endif // _COMMON_COMMONUTILS_H_