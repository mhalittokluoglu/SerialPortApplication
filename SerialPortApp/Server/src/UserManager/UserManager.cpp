#include "UserManager.h"
#include "CommandReceiver/CommandReceiverFactory.h"
#include "UserReceiver/UserReceiverFactory.h"
#include "Commands/ByteStream.h"
#include "Commands/DataElements.h"

UserManager::UserManager(ApplicationState *state, ISerialConnection *connection) : m_State{state}
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
        uint8_t commandBuffer[ByteStream::BUFFER_LENGTH];
        if (m_CommandReceiver->Read(commandBuffer))
        {
            char userInput[CommonSpecs::MAX_USER_INPUT] = {0};
            EnumUserInputType userInputType = m_UserReceiver->GetUserInput(userInput);
            m_UserCommandHandlerFacade->Handle(userInput, commandBuffer, userInputType);
        }
        else
        {
            *m_State = NO_MESSAGE_TO_SEND;
        }
    }
}