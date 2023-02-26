#include "UserReceiverFactory.h"
#ifdef USER_RECEIVER_DEFAULT
#include "UserReceiver.h"
#endif //USER_RECEIVER_DEFAULT
#include <cstddef>

IUserReceiver *UserReceiverFactory::CreateUserReceiver()
{
    IUserReceiver *receiver = NULL;

#ifdef USER_RECEIVER_DEFAULT
    receiver = new UserReceiver();
#endif //USER_RECEIVER_DEFAULT

    return receiver;
}
