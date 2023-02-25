import socket

class UdpServer:
    def __init__(self, ipAddress, port):
        self.m_IpAddress = ipAddress
        self.m_PortNumber = port
        self.__InitServer()
        self.m_Socket = socket.socket(family = socket.AF_INET, type = socket.SOCK_DGRAM)
        self.m_Socket.bind((self.m_IpAddress, self.m_PortNumber))

    def __InitServer(self):
        self.m_Socket = socket.socket(family = socket.AF_INET, type = socket.SOCK_DGRAM)
        self.m_Socket.bind((self.m_IpAddress, self.m_PortNumber))


    def ReceiveData(self):
        bytesAddressPair = self.m_Socket.recvfrom(1024)
        rawData = bytesAddressPair[0]
        address = bytesAddressPair[1]
        return rawData, address
