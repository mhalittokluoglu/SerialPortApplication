#include "SerialConnectionFactory.h"
#ifdef WINDOWS_SYSTEM
#include "WindowsSerialConnection.h"
#endif // WINDOWS_SYSTEM
#ifdef LINUX_SYSTEM
#include "LinuxSerialConnection.h"
#endif // LINUX_SYSTEM
#include <cstddef>

ISerialConnection *SerialConnectionFactory::CreateSerialConnection()
{
    ISerialConnection *connection = NULL;
#ifdef WINDOWS_SYSTEM
    connection = new WindowsSerialConnection();
#endif // WINDOWS_SYSTEM
#ifdef LINUX_SYSTEM
    connection = new LinuxSerialConnection();
#endif // LINUX_SYSTEM
    return connection;
}