#ifndef _CLIENTUTILS_H_
#define _CLIENTUTILS_H_
#include "Commands/DataElements.h"
#include "SerialConfiguration/ISerialConnection.h"
#include "Commands/ICommand.h"

class ClientUtils
{
public:
    static void Initialize(ISerialConnection *serialConnection);
    static bool SendInvalidRequestCommand(EnumInvalidCause cause);
    static bool SendCommand(ICommand *command);

private:
    static ISerialConnection *s_SerialConnection;

};
#endif // _CLIENTUTILS_H_