#ifndef _ICOMMANDPARSER_H_
#define _ICOMMANDPARSER_H_
#include <inttypes.h>
class ICommandParser
{
public:
    virtual ~ICommandParser() { }
    virtual bool ParseCommand(const char *commandLine, uint8_t *outputBuffer) = 0;
};
#endif // _ICOMMANDPARSER_H_