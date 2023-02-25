#ifndef _WINDOWSSOCKETCLIENT_H_
#define _WINDOWSSOCKETCLIENT_H_
#include <inttypes.h>
#include "SocketClient/ISocketClient.h"
#include <WS2tcpip.h>

class WindowsSocketClient : public ISocketClient
{

public:
    WindowsSocketClient(const char *ipAddress, uint32_t portNumber);
    void SendData(const char *data, int length);

private:
    const char *m_ServerIpAddress;
    uint32_t m_PortNumber;
    SOCKET m_ConnectionSocket;
    sockaddr_in m_ServerSocket;
};

#endif // _WINDOWSSOCKETCLIENT_H_