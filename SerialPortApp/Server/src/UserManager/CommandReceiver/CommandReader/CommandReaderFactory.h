#ifndef _COMMANDREADERFACTORY_H_
#define _COMMANDREADERFACTORY_H_

#include "ICommandReader.h"

class CommandReaderFactory
{
public:
    static ICommandReader *CreateCommandReader();
    
};

#endif // _COMMANDREADERFACTORY_H_