#ifndef _SERIALCONNECTIONFACTORY_H_
#define _SERIALCONNECTIONFACTORY_H_
#include "ISerialConnection.h"
#include "SerialConfiguration.h"
class SerialConnectionFactory
{
public:
    static ISerialConnection *CreateSerialConnection();

};
#endif // _SERIALCONNECTIONFACTORY_H_