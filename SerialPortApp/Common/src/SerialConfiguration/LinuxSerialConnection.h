#ifndef _LINUXSERIALCONNECTION_H_
#define _LINUXSERIALCONNECTION_H_

#include "SerialConfiguration/ISerialConnection.h"
#include "termios.h"

namespace Common
{
    class LinuxSerialConnection : public ISerialConnection
    {
    public:
        LinuxSerialConnection();
        ~LinuxSerialConnection();
        bool Initialize(const SerialConfiguration &configuration, int vTimeInDesiSecond = 0, int vMinInDesiSecond = 0);
        bool Send(char *buffer, int len);
        bool Receive(char *buffer, int &len);

    private:
        int m_SerialPortFileDescriptor;
        struct termios m_Options;
    };
} // Common
#endif // _LINUXSERIALCONNECTION_H_