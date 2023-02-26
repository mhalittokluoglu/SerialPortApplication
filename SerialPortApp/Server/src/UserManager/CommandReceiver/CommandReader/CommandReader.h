#ifndef _COMMANDREADER_H_
#define _COMMANDREADER_H_
#include "ICommandReader.h"
#include "Commands/DataElements.h"
#include "CommandParser/ICommandParser.h"
class CommandReader : public ICommandReader
{
public:
    CommandReader();
    ~CommandReader();
    void ReadFromFile(const char *fileName, uint8_t *buffer, uint32_t &length);

private:
    ICommandParser *m_Parsers[256];

private:
    EnumCommandType GetCommand(const char* commandString);

};
#endif // _COMMANDREADER_H_