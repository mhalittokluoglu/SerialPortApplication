#ifndef _COMMANDMANAGER_H_
#define _COMMANDMANAGER_H_
#include "IManager.h"
#include "IConnection.h"
#include "Commands/CommandProcessorFacade.h"

namespace Common
{
    class CommandManager : public IManager
    {
    public:
        void Run();

    protected:
        CommandManager(IConnection *connection);
        virtual ~CommandManager();
        IConnection *m_Connection;
        CommandProcessorFacade *m_Facade;
    };
} // Common
#endif // _COMMANDMANAGER_H_