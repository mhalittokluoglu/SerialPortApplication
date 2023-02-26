#include "CommandReceiverFactory.h"
#include <cstddef>
#ifdef COMMAND_RECEIVER_DEFAULT
#include "ServerCommandReceiver.h"
#endif // COMMAND_RECEIVER_DEFAULT


ICommandReceiver *CommandReceiverFactory::CreateCommandReceiver()
{
    ICommandReceiver *commandReceiver = NULL;

#ifdef COMMAND_RECEIVER_DEFAULT
    commandReceiver = new ServerCommandReceiver();
#endif // COMMAND_RECEIVER_DEFAULT

    return commandReceiver;
}

