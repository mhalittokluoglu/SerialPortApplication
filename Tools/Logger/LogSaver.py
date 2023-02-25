import time
import tkinter as tk
from tkinter import ttk


class LogSaver:
    def __init__(self, logSaverFrame, messageHandler, textBoxHandler, logConfiguration):
        self.__bIsFileCreated = False
        self.__mainFrame = logSaverFrame
        self.__messageHandler = messageHandler
        self.__textBoxHandler = textBoxHandler
        self.__logConfiguration = logConfiguration
        self.__InitGUI()
        self.__anyMessageReceived = False

    def __InitGUI(self):
        saveAllButton = ttk.Button(
            self.__mainFrame, text='Save All', command=self.SaveAll)
        saveFilteredButton = ttk.Button(self.__mainFrame, text='Save Filtered',
                                        command=self.SaveFiltered)
        clearButton = ttk.Button(self.__mainFrame, text='Clear', command = self.__ClearAllText)
        self.__saveAsANewFile = tk.BooleanVar()
        saveAsCheckButton = tk.Checkbutton(self.__mainFrame, text='Save As A New File',
                                            onvalue=True, offvalue=False, variable=self.__saveAsANewFile)
        saveAllButton.grid(row=0, column=0)
        clearButton.grid(row=0, column=1)
        saveFilteredButton.grid(row=0, column=2)
        saveAsCheckButton.grid(row=1, column=0, columnspan=3)

    def SaveAll(self):
        fileContent = self.__GetFileContent()
        if self.__saveAsANewFile.get() == True:
            self.__SaveAsANewFile(fileContent)
        else:
            self.__SaveFile(fileContent)

    def SaveFiltered(self):
        fileContent = self.__GetFilteredFileContent()
        if self.__saveAsANewFile.get() == True:
            self.__SaveAsANewFile(fileContent)
        else:
            self.__SaveFile(fileContent)

    def __SaveFile(self, fileContent):
        if self.__bIsFileCreated == False:
            self.fileName = self.__CreateFile()
        self.__SaveItToLogDir(self.fileName, fileContent)


    def __CreateFile(self):
        currentTime = time.localtime()
        year = currentTime.tm_year
        month = currentTime.tm_mon
        day = currentTime.tm_mday
        hour = currentTime.tm_hour
        min = currentTime.tm_min
        sec = currentTime.tm_sec
        fileName = str(year) + '_' + str(month) + '_' + str(day) + \
            '_' + str(hour) + '_' + str(min) + '_' + str(sec) + '.log'
        self.__bIsFileCreated = True
        return fileName

    def __SaveAsANewFile(self, fileContent):
        self.__bIsFileCreated = False
        self.__SaveFile(fileContent)

    def AutoSave(self):
        fileContent = self.__GetFileContent()
        if self.__anyMessageReceived == True:
            self.AutoSaveFileName = 'AutoSaved_' + self.__CreateFile()
            self.__SaveItToLogDir(self.AutoSaveFileName, fileContent)

    def FirstMessageReceived(self):
        self.__anyMessageReceived = True

    def __SaveItToLogDir(self, fileName, fileContent):
        import os
        if not os.path.exists('./LOG'):
            os.mkdir('LOG')
        with open('./LOG/' + fileName, 'w') as fileToSave:
            fileToSave.write(fileContent)

    def __GetFileContent(self):
        fileContent = ''
        for eachMessage in self.__messageHandler.m_MessageList:
            logLevelText = self.__logConfiguration.logLevelsList[eachMessage.logLevel]
            logTypeText = self.__logConfiguration.logTypesList[eachMessage.logType]
            fileContent += '[' + logLevelText + ':' + \
                logTypeText + '] ' + eachMessage.data
        return fileContent

    def __GetFilteredFileContent(self):
        fileContent = self.__textBoxHandler.m_TextBox.get("1.0", tk.END)
        return fileContent

    def __ClearAllText(self):
        self.__textBoxHandler.m_TextBox['state'] = tk.NORMAL
        self.__textBoxHandler.m_TextBox.delete('1.0',tk.END)
        self.__textBoxHandler.m_TextBox['state'] = tk.DISABLED
        self.__messageHandler.m_MessageList.clear()
