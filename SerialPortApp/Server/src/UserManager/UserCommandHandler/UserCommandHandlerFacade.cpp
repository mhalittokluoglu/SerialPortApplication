#include "UserCommandHandlerFacade.h"
#include "Commands/CommandUtils.h"

#include "UserCommandConverter/FirstCommandUserConverter.h"
#include "UserCommandConverter/InvalidUserCommandConverter.h"

#include "InvalidUserCommandHandler.h"
#include "UserFirstCommandHandler.h"

#include "Commands/FirstCommand.h"
#include "Commands/InvalidCommand.h"

#include <cstddef>

UserCommandHandlerFacade::UserCommandHandlerFacade(Common::IConnection *connection)
{
    m_UserCommandConverters[Common::COMMAND_1]          = new FirstCommandUserConverter();
    m_UserCommandConverters[Common::INVALID_COMMAND]    = new InvalidUserCommandConverter();

    m_UserCommandHandlers[Common::COMMAND_1]            = new UserFirstCommandHandler(connection);
    m_UserCommandHandlers[Common::INVALID_COMMAND]      = new InvalidUserCommandHandler(connection);

    m_Commands[Common::COMMAND_1]                       = new FirstCommand();
    m_Commands[Common::INVALID_COMMAND]                 = new InvalidCommand();
}

UserCommandHandlerFacade::~UserCommandHandlerFacade() { }

void UserCommandHandlerFacade::Handle(char *userInputBuffer, uint8_t *readedBuffer, EnumUserInputType inputType)
{
    Common::EnumCommandType commandType = Common::INVALID_COMMAND;
    if (inputType != INVALID)
    {
        uint8_t commandID = readedBuffer[2];
        commandType = Common::Utils::GetEnumTypeFromID(commandID);
    }
    
    if (m_Commands[commandType] != NULL)
        m_Commands[commandType]->Reset();

    if (m_UserCommandConverters[commandType]->Convert(m_Commands[commandType], readedBuffer, userInputBuffer))
        m_UserCommandHandlers[commandType]->Handle(m_Commands[commandType], inputType);
}