#include "UserReceiver.h"
#include "Constants.h"
#include <iostream>
#include <cstring>

UserReceiver::UserReceiver() { }

UserReceiver::~UserReceiver() { }

EnumUserInputType UserReceiver::GetUserInput(char *userInput)
{
    printf("Input > ");
    EnumUserInputType userInputType = INVALID;
    char upperCaseBuffer[Common::Constants::MAX_COMMAND_LENGTH] = { 0 };
    std::cin.getline(userInput, Common::Constants::MAX_COMMAND_LENGTH);
    int length = strlen(userInput);
    for(int i = 0; i < length; i++)
    {
        upperCaseBuffer[i] = toupper(userInput[i]);
    }

    if (strcmp(upperCaseBuffer, "CRC_OK") == 0)
    {
        userInputType = CRC_OK;
    }
    else if (strcmp(upperCaseBuffer, "CRC_ER") == 0)
    {
        userInputType = CRC_ER;
    }

    return userInputType;
}
