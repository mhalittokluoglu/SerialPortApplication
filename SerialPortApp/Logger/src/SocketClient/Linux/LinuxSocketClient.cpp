#include "LinuxSocketClient.h"

LinuxSocketClient::LinuxSocketClient(const char *ipAddress, uint32_t portNumber) : m_ServerIpAddress{ipAddress}, m_PortNumber{portNumber}
{
    m_ConnectionSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in serverSocket;
    m_ServerSocket.sin_addr.s_addr = inet_addr(m_ServerIpAddress);
    m_ServerSocket.sin_family = AF_INET;
    m_ServerSocket.sin_port = htons(m_PortNumber);
}

void LinuxSocketClient::SendData(const char *data, int length)
{
    sendto(m_ConnectionSocket, data, sizeof(char)*length, 0,
    (const struct sockaddr *)&m_ServerSocket, sizeof(m_ServerSocket));
}
