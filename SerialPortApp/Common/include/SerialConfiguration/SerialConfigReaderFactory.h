#ifndef _SERIALCONFIGREADERFACTORY_H_
#define _SERIALCONFIGREADERFACTORY_H_
#include "ISerialConfigReader.h"

namespace Common
{
    class SerialConfigReaderFactory
    {
    public:
        static ISerialConfigReader *CreateSerialConfigReader();
    };
} // Common

#endif // _SERIALCONFIGREADERFACTORY_H_