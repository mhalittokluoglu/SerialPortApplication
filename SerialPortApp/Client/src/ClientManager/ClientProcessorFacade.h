#ifndef _CLIENTPROCESSORFACADE_H_
#define _CLIENTPROCESSORFACADE_H_
#include "Commands/CommandProcessorFacade.h"

class ClientProcessorFacade : public Common::CommandProcessorFacade
{
public:
    ClientProcessorFacade();
    ~ClientProcessorFacade();
};
#endif // _CLIENTPROCESSORFACADE_H_