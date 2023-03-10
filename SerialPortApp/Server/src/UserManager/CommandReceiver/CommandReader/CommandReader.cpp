#include "CommandReader.h"
#include <fstream>
#include <sstream>
#include <cstring>
#ifdef LOG_ENABLED
#include "Logger.h"
#endif // LOG_ENABLED
#include "CommandParser/FirstCommandParser.h"
#include "Constants.h"

CommandReader::CommandReader()
{
    memset(m_Parsers, 0, sizeof(m_Parsers));
    m_Parsers[Common::COMMAND_1] = new FirstCommandParser();
    // Fill Here For More Commands
}

CommandReader::~CommandReader() { }

void CommandReader::ReadFromFile(const char *fileName, uint8_t *buffer, uint32_t &length)
{
    std::ifstream commandFile(fileName);
    char lineBuffer[1024] = { 0 };
    char commandTypeBuffer[256];

    int offset = 0;
    int i;
    for(i = 0;commandFile.getline(lineBuffer, sizeof(lineBuffer));i++)
    {
        memset(commandTypeBuffer, 0, sizeof(commandTypeBuffer));
        std::istringstream commandStream(lineBuffer);
        commandStream.getline(commandTypeBuffer, sizeof(commandTypeBuffer), ';');
        Common::EnumCommandType commandType = GetCommand(commandTypeBuffer);
        if (commandType == Common::MAX_COMMAND)
        {
#ifdef LOG_ENABLED
            Logger::LOG_ERROR(COMPONENT_COMMON, "Unknown CommandType: %s in line: %d", commandTypeBuffer, i + 1);
#endif // LOG_ENABLED
            offset++;
            continue;
        }
        if (m_Parsers[commandType] == NULL)
        {
#ifdef LOG_ENABLED
            Logger::LOG_DEBUG(COMPONENT_COMMON, "CommandType %s is not implemented yet! line: %d", commandTypeBuffer, i + 1);
#endif // LOG_ENABLED
            offset++;
            continue;
        }

        if (!m_Parsers[commandType]->ParseCommand(lineBuffer, &buffer[(i - offset)* Common::Constants::MAX_COMMAND_LENGTH]))
        {
            memset(&buffer[i], 0, Common::Constants::MAX_COMMAND_LENGTH);
            offset++;
            continue;
#ifdef LOG_ENABLED
            Logger::LOG_ERROR(COMPONENT_COMMON, "Unable to Parser CommandType %s in line: %d", commandTypeBuffer, i + 1);
#endif // LOG_ENABLED
        }

    }
    length = i - offset;

    commandFile.close();
}

Common::EnumCommandType CommandReader::GetCommand(const char* commandString)
{
    Common::EnumCommandType commandType = Common::MAX_COMMAND;
    
    if (strcmp(commandString, "COMMAND_1") == 0)
        commandType = Common::COMMAND_1;
    else if (strcmp(commandString, "COMMAND_2") == 0)
        commandType = Common::COMMAND_2;
    else if (strcmp(commandString, "INVALID_COMMAND") == 0)
        commandType = Common::INVALID_COMMAND;

    return commandType;
}

