#include "UserReceiver.h"
#include <iostream>
#include <cstring>
#include "Commands/DataElements.h"

UserReceiver::UserReceiver() { }

UserReceiver::~UserReceiver() { }

EnumUserInputType UserReceiver::GetUserInput(char *userInput)
{
    printf("Input > ");
    EnumUserInputType userInputType = INVALID;
    char upperCaseBuffer[CommonSpecs::MAX_USER_INPUT] = { 0 };
    std::cin.getline(userInput, CommonSpecs::MAX_USER_INPUT);
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
