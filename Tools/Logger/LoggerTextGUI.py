import tkinter as tk
from tkinter import ttk
from tkinter import font


class TextBoxHandler:
    def __init__(self, frame, logConfiguration):
        self.__m_LogLevelsList = logConfiguration.logLevelsList
        self.__m_LogTypesList = logConfiguration.logTypesList
        frame.columnconfigure(0, weight=1)
        frame.rowconfigure(0, weight = 0)
        frame.rowconfigure(1, weight=1)
        self.__m_TextBoxEditorFrame = ttk.Frame(frame)
        self.__m_TextBoxFrame = ttk.Frame(frame)
        self.__m_TextBoxEditorFrame.grid(row=0, column=0, sticky = tk.N)
        self.__m_TextBoxFrame.grid(row=1, column=0, sticky = tk.N + tk.E + tk.S + tk.W)

        self.__InitGUI()

    def __InitGUI(self):
        self.__InitTextBoxGUI()
        self.__InitTextBoxEditorGUI()

    def __InitTextBoxGUI(self):
        self.__m_TextBoxFrame.columnconfigure(0, weight=1)
        self.__m_TextBoxFrame.rowconfigure(0, weight=1)
        self.m_TextBox = tk.Text(self.__m_TextBoxFrame, background='#AAAAAA')
        self.m_ScrollBar = ttk.Scrollbar(
            self.__m_TextBoxFrame, command=self.m_TextBox.yview)
        self.m_TextBox.configure(yscrollcommand=self.m_ScrollBar.set)
        self.m_TextBox.bind('<MouseWheel>', self.__OnMouseWheel)
        self.m_TextBox['state'] = tk.DISABLED

        self.m_TextBox.grid(row=0, column=0, sticky=tk.N + tk.E + tk.S + tk.W)
        self.m_ScrollBar.grid(row=0, column=1, sticky=tk.N + tk.S)

    def __InitTextBoxEditorGUI(self):
        highLightButton = ttk.Button(self.__m_TextBoxEditorFrame, text='Highlight',
                                     command=self.__HighlightFont)
        highLightButton.grid(row = 0, column = 0)
        unHighLightButton = ttk.Button(self.__m_TextBoxEditorFrame, text='Unhighlight',
                                     command=self.__UnHighlightFont)
        unHighLightButton.grid(row = 0, column = 1)

    def AppendMessage(self, message):
        logLevelText = self.__m_LogLevelsList[message.logLevel]
        logTypeText = self.__m_LogTypesList[message.logType]
        first = self.m_TextBox.index(tk.INSERT)
        self.m_TextBox['state'] = tk.NORMAL
        self.m_TextBox.insert(
            tk.END, '[' + logLevelText + ': ' + logTypeText + '] ' + message.data)
        end = self.m_TextBox.index(tk.INSERT)
        if logLevelText == 'ERROR':
            self.__SetErrorFont(first, end)
        elif logLevelText == 'WARNING':
            self.__SetWarningFont(first, end)
        elif logLevelText == 'INFO':
            self.__SetInfoFont(first, end)

        self.m_TextBox['state'] = tk.DISABLED

    def UpdateAllMessages(self, messages):
        self.m_TextBox['state'] = tk.NORMAL
        self.m_TextBox.delete("1.0", tk.END)
        self.m_TextBox['state'] = tk.DISABLED
        for eachMessage in messages:
            self.AppendMessage(eachMessage)

    def __OnMouseWheel(self, event):
        self.m_TextBox.yview("scroll", -int(event.delta/120), "units")

    def __SetErrorFont(self, first, end):
        errorFont = font.Font(self.m_TextBox, self.m_TextBox.cget('font'))
        self.m_TextBox.tag_configure(
            'errorFont', font=errorFont, foreground='#FFCCCC')
        self.m_TextBox.tag_add('errorFont', first, end)

    def __SetWarningFont(self, first, end):
        warningFont = font.Font(self.m_TextBox, self.m_TextBox.cget('font'))
        self.m_TextBox.tag_configure(
            'warningFont', font=warningFont, foreground='#FDFDAA')
        self.m_TextBox.tag_add('warningFont', first, end)

    def __SetInfoFont(self, first, end):
        infoFont = font.Font(self.m_TextBox, self.m_TextBox.cget('font'))
        self.m_TextBox.tag_configure(
            'infoFont', font=infoFont, foreground='#CCFFCC')
        self.m_TextBox.tag_add('infoFont', first, end)

    def __HighlightFont(self):
        self.m_TextBox['state'] = tk.NORMAL
        highlightFont = font.Font(self.m_TextBox, self.m_TextBox.cget('font'))
        self.m_TextBox.tag_configure(
            'highlightFont', font=highlightFont, background='#3535A0')
        currentTags = self.m_TextBox.tag_names('sel.first')
        if 'highlightFont' not in currentTags:
            self.m_TextBox.tag_add('highlightFont', 'sel.first', 'sel.last')
        self.m_TextBox['state'] = tk.DISABLED

    def __UnHighlightFont(self):
        self.m_TextBox['state'] = tk.NORMAL
        currentTags = self.m_TextBox.tag_names('sel.first')
        if 'highlightFont' in currentTags:
            self.m_TextBox.tag_remove('highlightFont', 'sel.first', 'sel.last')
        self.m_TextBox['state'] = tk.DISABLED