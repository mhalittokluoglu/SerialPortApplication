#ifndef _DATAELEMENTS_H_
#define _DATAELEMENTS_H_
#include <inttypes.h>
enum EnumCommandType
{
    COMMAND_1,
    COMMAND_2,
    INVALID_REQUEST_COMMAND,
    INVALID_COMMAND,
    MAX_COMMAND
};

extern const uint8_t CommandMap[MAX_COMMAND];

enum EnumError
{
    ERROR = 0,
    NO_ERROR = 1
};

enum EnumSignalState
{
    LOW = 0,
    HIGH = 1
};

enum EnumLoadState
{
    NO_LOAD = 0,
    A_LOADED = 1,
    B_LOADED = 2,
    C_LOADED = 3
};

enum EnumInvalidCause
{
    NO_INVALID_CAUSE = 0,
    MESSAGE_WITH_CRC_ERROR = 1,
    INVALID_MESSAGE = 2
};

struct CommonSpecs
{
    static const uint32_t MAX_COMMAND_TYPE = 25;
    static const uint32_t MAX_USER_INPUT = 255;

    static EnumCommandType GetEnumTypeFromID(uint8_t commandID);
};

#endif // _DATAELEMENTS_H_