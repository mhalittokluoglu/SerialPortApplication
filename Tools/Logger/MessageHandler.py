import tkinter as tk
from tkinter import ttk


class MessageHandler:
    def __init__(self, logConfiguration, frame, textGUI):
        self.__m_LogLevelsList = logConfiguration.logLevelsList
        self.__m_LogTypesList = logConfiguration.logTypesList
        self.m_LogLevelsFilters = []
        self.m_LogTypesFilters = []
        self.__textGUI = textGUI
        self.__CreateFilters()
        self.m_MessageList = []
        self.m_FilteredMessageList = []
        self.__InitiateGUI(frame)

    def SetSaver(self, saver):
        self.__bFirstMessageReceived = False
        self.__AutoSaver = saver

    def __CreateFilters(self):
        for i in range(0, len(self.__m_LogLevelsList)):
            boolVar = tk.BooleanVar()
            self.m_LogLevelsFilters.append(boolVar)

        for i in range(0, len(self.__m_LogTypesList)):
            boolVar = tk.BooleanVar()
            self.m_LogTypesFilters.append(boolVar)

    def MessageReceived(self, message):
        self.m_MessageList.append(message)
        if self.__MessageValidForCurrentFilter(message):
            self.__textGUI.AppendMessage(message)
        if self.__bFirstMessageReceived == False:
            self.__AutoSaver.FirstMessageReceived()
            self.__bFirstMessageReceived = True

    def __InitiateGUI(self, frame):
        logLevelFrame = ttk.Frame(frame)
        logLevelFrame.grid(row=0, column=0, sticky = tk.W)
        logLevelLabel = tk.Label(logLevelFrame, text='Log Level: ', fg='black')
        checkAllLogLevelsButton = ttk.Button(logLevelFrame, text='Check All Levels',
                                            command=self.__SetLogLevelFilters)
        clearAllLogLevelsButton = ttk.Button(logLevelFrame, text='Clear All Levels',
                                            command=self.__ClearLogLevelFilters)
        for i in range(0, len(self.__m_LogLevelsList)):
            checkButton = tk.Checkbutton(logLevelFrame, text=self.__m_LogLevelsList[i],
                                         variable=self.m_LogLevelsFilters[i], onvalue=True, offvalue=False,
                                         command=self.__CheckLogEvent)
            checkButton.grid(row=1, column=i)
        logLevelLabel.grid(row=0, column=0, sticky = tk.W + tk.N)
        checkAllLogLevelsButton.grid(row=2, column=0)
        clearAllLogLevelsButton.grid(row=2, column=1)

        logTypeFrame = ttk.Frame(frame)
        logTypeFrame.grid(row=1, column=0, sticky = tk.W)
        logTypeLabel = tk.Label(logTypeFrame, text='Log Type: ', fg='black')
        checkAllLogTypessButton = ttk.Button(logTypeFrame, text='Check All Types',
                                            command=self.__SetLogTypeFilters)
        clearAllLogTypesButton = ttk.Button(logTypeFrame, text='Clear All Types',
                                           command=self.__ClearLogTypeFilters)
        for i in range(0, len(self.__m_LogTypesList)):
            checkButton = tk.Checkbutton(logTypeFrame, text=self.__m_LogTypesList[i],
                                         variable=self.m_LogTypesFilters[i], onvalue=True, offvalue=False,
                                         command=self.__CheckLogEvent)
            checkButton.grid(row=1, column=i)
        logTypeLabel.grid(row=0, column=0, sticky = tk.W + tk.N)
        checkAllLogTypessButton.grid(row=2, column=0)
        clearAllLogTypesButton.grid(row=2, column=1)
        self.__SetAllFiltersAsTrue()

    def __CheckLogEvent(self):
        self.__textBoxMutex.acquire()
        self.m_FilteredMessageList.clear()
        for eachMessage in self.m_MessageList:
            self.__MessageValidForCurrentFilter(eachMessage)

        self.__textGUI.UpdateAllMessages(self.m_FilteredMessageList)
        self.__textBoxMutex.release()

    def __MessageValidForCurrentFilter(self, message):
        if message.logLevel > -1 and message.logType > -1:
            isLevelValid = self.m_LogLevelsFilters[message.logLevel].get()
            isTypeValid = self.m_LogTypesFilters[message.logType].get()
            if isLevelValid == True and isTypeValid == True:
                self.m_FilteredMessageList.append(message)
                return True
        return False

    def __SetAllFiltersAsTrue(self):
        for boolVar in self.m_LogLevelsFilters:
            boolVar.set(True)
        for boolVar in self.m_LogTypesFilters:
            boolVar.set(True)

    def __SetLogLevelFilters(self):
        for boolVar in self.m_LogLevelsFilters:
            boolVar.set(True)
        self.__CheckLogEvent()

    def __SetLogTypeFilters(self):
        for boolVar in self.m_LogTypesFilters:
            boolVar.set(True)
        self.__CheckLogEvent()

    def __ClearLogLevelFilters(self):
        for boolVar in self.m_LogLevelsFilters:
            boolVar.set(False)
        self.__CheckLogEvent()

    def __ClearLogTypeFilters(self):
        for boolVar in self.m_LogTypesFilters:
            boolVar.set(False)
        self.__CheckLogEvent()

    def SetMutex(self, mutex):
        self.__textBoxMutex = mutex
