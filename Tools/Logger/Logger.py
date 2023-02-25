import tkinter as tk
from tkinter import ttk
import MessageReceiverManager as mrm
import LogConfiguration as lc
import MessageHandler as mh
import LoggerTextGUI as ltg
import LogSaver as ls
import signal


class LoggerApplication:
    def __init__(self):
        self.__mainWindow = tk.Tk()
        try:
            self.__mainWindow.iconbitmap('Logger.ico')
        except:
            print('Logger.ico not found!')
        self.__mainWindow.title('Logger v2')
        self.__InitiateGUI()
        self.__InitiateMessageReceiver()
        self.__InitiateAutoSaver()
        self.__mainWindow.mainloop()

    def __InitiateGUI(self):
        screen_width = self.__mainWindow.winfo_screenwidth()
        screen_height = self.__mainWindow.winfo_screenheight()
        self.__mainWindow.geometry(
            f"{int(screen_width / 2)}x{int(screen_height / 2)}")
        self.__mainWindow.rowconfigure(1, weight=1)
        self.__mainWindow.columnconfigure(0, weight=1)
        self.__InitiateFrames()
        self.__mainWindow.protocol(
            'WM_DELETE_WINDOW', self.__ApplicationClosed)

    def __InitiateMessageReceiver(self):
        ipAddress = '127.0.0.1'
        portNumber = 30000
        self.__logConfiguration = lc.LogConfigurations()
        self.__loggerTextGUI = ltg.TextBoxHandler(
            self.__lowerFrame, self.__logConfiguration)
        self.__messageHandler = mh.MessageHandler(
            self.__logConfiguration, self.__loggerHandlerFrame, self.__loggerTextGUI)

        self.__messageReceiverManager = \
            mrm.MessageReceiveManager(ipAddress, portNumber,
                                      self.__messageHandler, self.__logConfiguration)

    def __InitiateAutoSaver(self):
        self.__logSaver = ls.LogSaver(self.__saverFrame, self.__messageHandler,
        self.__loggerTextGUI, self.__logConfiguration)
        self.__messageHandler.SetSaver(self.__logSaver)

    def __InitiateFrames(self):
        self.__loggerHandlerFrame = ttk.Frame(self.__mainWindow)
        self.__saverFrame = ttk.Frame(self.__mainWindow)
        self.__lowerFrame = ttk.Frame(self.__mainWindow)
        self.__lowerFrame.columnconfigure(0, weight=1)
        self.__lowerFrame.rowconfigure(0, weight=1)

        self.__loggerHandlerFrame.grid(row=0, column=0, sticky=tk.N + tk.E + tk.W)
        self.__saverFrame.grid(row=0, column=1, sticky=tk.N + tk.E + tk.W)
        self.__lowerFrame.grid(
            row=1, column=0, columnspan = 2, sticky=tk.N + tk.S + tk.E + tk.W)

    def __ApplicationClosed(self):
        self.__logSaver.AutoSave()
        import os
        pid = os.getpid()
        os.kill(pid, signal.SIGTERM)

LoggerApp = LoggerApplication()
