#ifndef _ICOMMANDPROCESSOR_H_
#define _ICOMMANDPROCESSOR_H_
#include <inttypes.h>
class ICommandProcessor
{
public:
    virtual ~ICommandProcessor() { }
    virtual void Process(uint8_t *buffer) = 0;
    
};
#endif // _ICOMMANDPROCESSOR_H_