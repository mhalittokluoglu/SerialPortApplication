#ifndef _COMMON_CONSTANTS_H_
#define _COMMON_CONSTANTS_H_
#include <inttypes.h>
namespace Common
{
    struct Constants
    {
        static const uint32_t MAX_COMMAND_TYPE = 25;
        static const uint32_t MAX_COMMAND_LENGTH = 255;
    };
} // Common

#endif // _COMMON_CONSTANTS_H_