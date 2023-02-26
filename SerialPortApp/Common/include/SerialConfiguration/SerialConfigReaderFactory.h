#ifndef _SERIALCONFIGREADERFACTORY_H_
#define _SERIALCONFIGREADERFACTORY_H_
#include "ISerialConfigReader.h"


class SerialConfigReaderFactory
{
public:
    static ISerialConfigReader* CreateSerialConfigReader();
};


#endif // _SERIALCONFIGREADERFACTORY_H_