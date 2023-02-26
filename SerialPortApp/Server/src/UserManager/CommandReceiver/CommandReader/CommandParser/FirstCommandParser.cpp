#include "FirstCommandParser.h"
#include <sstream>
#include <cstring>
#include "Commands/DataElements.h"


FirstCommandParser::FirstCommandParser() { }

FirstCommandParser::~FirstCommandParser() { }

bool FirstCommandParser::ParseCommand(const char *commandLine, uint8_t *outputBuffer)
{
    bool bResult = true;
    std::istringstream commandStream(commandLine);
    char buffer[256] = { 0 };

    commandStream.getline(buffer, sizeof(buffer), ';'); // CommandType
    
    memset(buffer, 0, sizeof(buffer));
    commandStream.getline(buffer, sizeof(buffer), ';'); // Data A
    uint8_t dataA = strtol(buffer, NULL, 0);

    // TODO: Add Data Validation

    memset(buffer, 0, sizeof(buffer));
    commandStream.getline(buffer, sizeof(buffer), ';'); // Data B
    float dataB = atof(buffer);

    // TODO: Add Data Validation

    outputBuffer[0] = 0xCA; // heading
    outputBuffer[1] = 0x09; // length
    outputBuffer[2] = CommandMap[COMMAND_1];
    outputBuffer[3] = dataA;
    memcpy(&outputBuffer[4], &dataB, sizeof(dataB));

    return bResult;
}
    