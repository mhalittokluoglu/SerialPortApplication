#ifndef _CLIENTUTILS_H_
#define _CLIENTUTILS_H_
#include "Commands/DataElements.h"
#include "IConnection.h"
#include "Commands/ISerializableCommand.h"

class ClientUtils
{
public:
    static void Initialize(Common::IConnection *connection);
    static bool SendInvalidRequestCommand(Common::EnumInvalidCause cause);
    static bool SendCommand(Common::ISerializableCommand *command);

private:
    static Common::IConnection *s_Connection;

};
#endif // _CLIENTUTILS_H_