#ifndef _SERVERPROCESSORFACADE_H_
#define _SERVERPROCESSORFACADE_H_
#include "Commands/CommandProcessorFacade.h"
class ServerProcessorFacade : public Common::CommandProcessorFacade
{
public:
    ServerProcessorFacade();
    ~ServerProcessorFacade();
};
#endif // _SERVERPROCESSORFACADE_H_