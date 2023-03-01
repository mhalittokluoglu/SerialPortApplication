#ifndef _ICOMMANDRECEIVER_H_
#define _ICOMMANDRECEIVER_H_
#include <inttypes.h>
class ICommandReceiver
{
public:
    virtual ~ICommandReceiver() { }
    virtual bool Read(uint8_t *buffer) = 0;
};
#endif // _ICOMMANDRECEIVER_H_