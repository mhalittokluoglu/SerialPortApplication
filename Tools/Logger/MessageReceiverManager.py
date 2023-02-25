import threading
import UdpServer
from Message import *

class MessageReceiveManager:
    def __init__(self, ipAddress, portNumber, messageHandler, logConfiguration):
        self.m_MessageHandler = messageHandler
        self.m_Socket = UdpServer.UdpServer(ipAddress, portNumber)
        self.m_ListenerThread = threading.Thread(target = self.__DataReceivedEvent)
        self.m_TextBoxMutex = threading.Lock()
        self.m_MessageHandler.SetMutex(self.m_TextBoxMutex)
        self.m_LogLevelsList = logConfiguration.logLevelsList
        self.m_LogTypesList = logConfiguration.logTypesList
        self.m_ListenerThread.start()

    def __DataReceivedEvent(self):
        while True:
            rawData, address = self.m_Socket.ReceiveData()
            message = self.__ConvertRawDataToMessage(rawData.decode('utf-8'))
            if message != -1:
                self.m_TextBoxMutex.acquire()
                self.m_MessageHandler.MessageReceived(message)
                self.m_TextBoxMutex.release()

    def __ConvertRawDataToMessage(self, rawData):
        try:
            message = Message()
            message.logLevel = int(rawData[0])
            message.logType = int(rawData[1])
            message.data = rawData[2:]
            return message
        except:
            print(f"Error when parsing {rawData}")
            return -1
        