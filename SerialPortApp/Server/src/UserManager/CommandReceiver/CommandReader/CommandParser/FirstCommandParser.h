#ifndef _FIRSTCOMMANDPARSER_H_
#define _FIRSTCOMMANDPARSER_H_
#include "ICommandParser.h"
class FirstCommandParser : public ICommandParser
{
public:
    FirstCommandParser();
    ~FirstCommandParser();
    virtual bool ParseCommand(const char *commandLine, uint8_t *outputBuffer);
    
};
#endif // _FIRSTCOMMANDPARSER_H_