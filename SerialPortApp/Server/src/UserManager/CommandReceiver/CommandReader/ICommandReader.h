#ifndef _ICOMMANDREADER_H_
#define _ICOMMANDREADER_H_
#include <inttypes.h>
class ICommandReader
{
public:
    virtual ~ICommandReader() { }
    virtual void ReadFromFile(const char *fileName, uint8_t *buffer, uint32_t &length) = 0;
};
#endif // _ICOMMANDREADER_H_