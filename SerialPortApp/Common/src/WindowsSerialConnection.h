#ifndef _WINDOWSSERIALCONNECTION_H_
#define _WINDOWSSERIALCONNECTION_H_
#include "ISerialConnection.h"
#include <Windows.h>
class WindowsSerialConnection : public ISerialConnection
{
public:
    WindowsSerialConnection();
    ~WindowsSerialConnection();
    bool Initialize(const SerialConfiguration &configuration, int vTime= 0, int vMin = 0);
    bool Send(char *buffer, int len);
    bool Receive(char *buffer, int &len);
private:
    HANDLE m_SerialHandle;

};

#endif // _WINDOWSSERIALCONNECTION_H_