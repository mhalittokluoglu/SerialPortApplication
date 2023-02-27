#include "InvalidUserCommandConverter.h"
#include "Commands/InvalidCommand.h"
#include <cstddef>
#include <cstring>

InvalidUserCommandConverter::InvalidUserCommandConverter() { }

InvalidUserCommandConverter::~InvalidUserCommandConverter() { }

bool InvalidUserCommandConverter::Convert(ICommand *command, uint8_t *commandBuffer, char* userBuffer)
{
    InvalidCommand *invalidCommand = static_cast<InvalidCommand*>(command);

    if (invalidCommand == NULL)
        return false;

    
    size_t length = strlen(userBuffer);
    memcpy(&invalidCommand->m_Data, userBuffer, length);

    return true;
}