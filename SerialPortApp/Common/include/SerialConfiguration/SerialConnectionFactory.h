#ifndef _SERIALCONNECTIONFACTORY_H_
#define _SERIALCONNECTIONFACTORY_H_
#include "ISerialConnection.h"
#include "SerialConfiguration.h"

namespace Common
{
    class SerialConnectionFactory
    {
    public:
        static ISerialConnection *CreateSerialConnection();
    };
} // Common

#endif // _SERIALCONNECTIONFACTORY_H_