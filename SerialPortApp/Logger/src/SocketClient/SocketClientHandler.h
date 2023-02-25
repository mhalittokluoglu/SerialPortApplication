#ifndef _LOGGER_SOCKETCLIENTHANDLER_H_
#define _LOGGER_SOCKETCLIENTHANDLER_H_
#include "ISocketClient.h"
#include <inttypes.h>

class SocketClientHandler
{
public:
    SocketClientHandler(const char *ipAddr, uint32_t portNumber);
    void SendData(const char *data, int length);
private:
    const char *m_IpAddress;
    uint32_t m_PortNumber;
    ISocketClient *m_ConnectionSocket;
};

#endif