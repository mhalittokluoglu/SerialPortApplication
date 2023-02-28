#include "FirstCommandUserConverter.h"
#include "Commands/FirstCommand.h"
#include <cstddef>
#include <cstring>

FirstCommandUserConverter::FirstCommandUserConverter() { }

FirstCommandUserConverter::~FirstCommandUserConverter() { }

bool FirstCommandUserConverter::Convert(Common::ICommand *command, uint8_t *commandBuffer, char* userBuffer)
{
    FirstCommand *command1 = static_cast<FirstCommand*>(command);
    if (command1 == NULL)
        return false;
    
    memcpy(&command1->m_Header.m_Heading, &commandBuffer[0], sizeof(uint8_t));
    memcpy(&command1->m_Header.m_CommandLength, &commandBuffer[1], sizeof(uint8_t));
    memcpy(&command1->m_Header.m_CommandNo, &commandBuffer[2], sizeof(uint8_t));

    uint8_t dataA;
    memcpy(&dataA, &commandBuffer[3], sizeof(uint8_t));
    command1->m_A.Deserialize(dataA);
    memcpy(&command1->m_B, &commandBuffer[4], sizeof(float));

    return true;
}
