#include "WindowsSocketClient.h"

WindowsSocketClient::WindowsSocketClient(const char *ipAddress, uint32_t portNumber) : m_ServerIpAddress{ipAddress}, m_PortNumber{portNumber}
{
#pragma comment(lib, "WS2_32")
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int32_t wsOk = WSAStartup(ver, &wsData);
    m_ConnectionSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in serverSocket;
    m_ServerSocket.sin_addr.s_addr = inet_addr(m_ServerIpAddress);
    m_ServerSocket.sin_family = AF_INET;
    m_ServerSocket.sin_port = htons(m_PortNumber);
}

void WindowsSocketClient::SendData(const char* data, int length)
{
    sendto(m_ConnectionSocket, data, sizeof(char)*length, 0,
    (const struct sockaddr *)&m_ServerSocket, sizeof(m_ServerSocket));
}
