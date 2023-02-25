#ifndef _ISERIALCONNECTION_H_
#define _ISERIALCONNECTION_H_
#include "SerialConfiguration.h"
class ISerialConnection
{
public:
    virtual ~ISerialConnection() { }
    virtual bool Initialize(const SerialConfiguration &configuration, int vTime= 0, int vMin = 0) = 0;
    virtual bool Send(char *buffer, int len) = 0;
    virtual bool Receive(char *buffer, int &len) = 0;
};
#endif // _ISERIALCONNECTION_H_