#ifndef _WINDOWSSERIALCONNECTION_H_
#define _WINDOWSSERIALCONNECTION_H_
#include "SerialConfiguration/ISerialConnection.h"
#include <Windows.h>
namespace Common
{
    class WindowsSerialConnection : public ISerialConnection
    {
    public:
        WindowsSerialConnection();
        ~WindowsSerialConnection();
        bool Initialize(const SerialConfiguration &configuration, int vTimeInDesiSecond = 0, int vMinInDesiSecond = 0);
        bool Send(char *buffer, int len);
        bool Receive(char *buffer, int &len);

    private:
        HANDLE m_SerialHandle;
    };
} // Common

#endif // _WINDOWSSERIALCONNECTION_H_