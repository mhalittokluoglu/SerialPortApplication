#include "UserCommandHandlerFacade.h"
#include "Commands/DataElements.h"

#include "UserCommandConverter/FirstCommandUserConverter.h"
#include "UserCommandConverter/InvalidUserCommandConverter.h"

#include "InvalidUserCommandHandler.h"
#include "UserFirstCommandHandler.h"

#include "Commands/FirstCommand.h"
#include "Commands/InvalidCommand.h"

#include "SerialConfiguration/SerialConfigReaderFactory.h"
#include <cstddef>

UserCommandHandlerFacade::UserCommandHandlerFacade(ISerialConnection *connection)
{
    m_UserCommandConverters[COMMAND_1]          = new FirstCommandUserConverter();
    m_UserCommandConverters[INVALID_COMMAND]    = new InvalidUserCommandConverter();

    m_UserCommandHandlers[COMMAND_1]            = new UserFirstCommandHandler(connection);
    m_UserCommandHandlers[INVALID_COMMAND]      = new InvalidUserCommandHandler(connection);

    m_Commands[COMMAND_1]                       = new FirstCommand();
    m_Commands[INVALID_COMMAND]                 = new InvalidCommand();
}

UserCommandHandlerFacade::~UserCommandHandlerFacade() { }

void UserCommandHandlerFacade::Handle(char *userInputBuffer, uint8_t *readedBuffer, EnumUserInputType inputType)
{
    EnumCommandType commandType = INVALID_COMMAND;
    if (inputType != INVALID)
    {
        uint8_t commandID = readedBuffer[2];
        commandType = CommonSpecs::GetEnumTypeFromID(commandID);
    }
    
    if (m_Commands[commandType] != NULL)
        m_Commands[commandType]->Reset();

    if (m_UserCommandConverters[commandType]->Convert(m_Commands[commandType], readedBuffer, userInputBuffer))
        m_UserCommandHandlers[commandType]->Handle(m_Commands[commandType], inputType);
}