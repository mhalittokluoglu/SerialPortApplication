#include "SocketClientHandler.h"
#ifdef WINDOWS_SYSTEM
#include "Windows/WindowsSocketClient.h"
#endif
#ifdef LINUX_SYSTEM
#include "Linux/LinuxSocketClient.h"
#endif

SocketClientHandler::SocketClientHandler(const char *ipAddr, uint32_t portNumber) : m_IpAddress{ipAddr},
                                                                                    m_PortNumber{portNumber}
{
#ifdef LINUX_SYSTEM
    m_ConnectionSocket = new LinuxSocketClient(m_IpAddress, m_PortNumber);
#endif
#ifdef WINDOWS_SYSTEM
    m_ConnectionSocket = new WindowsSocketClient(m_IpAddress, m_PortNumber);
#endif
}

void SocketClientHandler::SendData(const char *data, int length)
{
    m_ConnectionSocket->SendData(data, length);
}
