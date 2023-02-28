#include "UserManager.h"
#include "CommandReceiver/CommandReceiverFactory.h"
#include "UserReceiver/UserReceiverFactory.h"
#include "Constants.h"

using namespace Common;

UserManager::UserManager(ApplicationState *state, IConnection *connection) : m_State{state}
{
    m_CommandReceiver = CommandReceiverFactory::CreateCommandReceiver();
    m_UserReceiver = UserReceiverFactory::CreateUserReceiver();
    m_UserCommandHandlerFacade = new UserCommandHandlerFacade(connection);
}

UserManager::~UserManager() {}

void UserManager::Run()
{
    if (*m_State != NO_MESSAGE_TO_SEND)
    {
        uint8_t commandBuffer[Constants::MAX_COMMAND_LENGTH];
        if (m_CommandReceiver->Read(commandBuffer))
        {
            char userInput[Constants::MAX_COMMAND_LENGTH] = {0};
            EnumUserInputType userInputType = m_UserReceiver->GetUserInput(userInput);
            m_UserCommandHandlerFacade->Handle(userInput, commandBuffer, userInputType);
        }
        else
        {
            *m_State = NO_MESSAGE_TO_SEND;
        }
    }
}