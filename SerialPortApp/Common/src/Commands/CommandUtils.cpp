#include "Commands/CommandUtils.h"

using namespace Common;

const uint8_t Utils::CommandMap[MAX_COMMAND] = {
    0xA8,
    0xA9,
    0xA5
};

EnumCommandType Utils::GetEnumTypeFromID(uint8_t commandID)
{
    EnumCommandType type = INVALID_COMMAND;
    switch (commandID)
    {
    case 0xA8:
        type = EnumCommandType::COMMAND_1;
        break;

    case 0xA9:
        type = EnumCommandType::COMMAND_2;
        break;

    case 0xA5:
        type = EnumCommandType::INVALID_REQUEST_COMMAND;
        break;
        
    default:
        break;
    }
    return type;
}
