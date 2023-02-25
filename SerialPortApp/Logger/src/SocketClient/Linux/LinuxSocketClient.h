#ifndef _LINUXSOCKETCLIENT_H_
#define _LINUXSOCKETCLIENT_H_
#include <inttypes.h>
#include "SocketClient/ISocketClient.h"
#include <sys/socket.h>
#include <arpa/inet.h>

class LinuxSocketClient : public ISocketClient
{

public:
    LinuxSocketClient(const char *ipAddress, uint32_t portNumber);
    void SendData(const char* data, int length);

private:
    const char *m_ServerIpAddress;
    uint32_t m_PortNumber;
    int64_t m_ConnectionSocket;
    sockaddr_in m_ServerSocket;
};
#endif