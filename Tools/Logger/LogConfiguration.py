class LogConfigurations:
    def __init__(self):
        self.logLevelsList = []
        self.logTypesList = []
        self.enumLogLevelsMap = {}
        self.enumlogTypesMap = {}
        self.__LoadLogConfiguration()
        self.__FillLogLists()

    def __LoadLogConfiguration(self):
        with open('LogConfiguration.csv', 'r') as loggerConfigurationFile:
            lines = loggerConfigurationFile.readlines()
            state = 'unkown'
            for eachLine in lines:
                splittedLine = eachLine.split(',')
                if splittedLine[0] == 'LogLevels':
                    state = 'LogLevel'
                elif splittedLine[0] == 'LogTypes':
                    state = 'LogType'
                else:
                    if state == 'LogLevel':
                        self.enumLogLevelsMap[int(splittedLine[1])] = splittedLine[0]
                    elif state == 'LogType':
                        self.enumlogTypesMap[int(splittedLine[1])] = splittedLine[0]
                    else:
                        print(f'Error in LogConfigurations __LoadConfiguration, \
                            ParseError: state is {state}')
    
    def __FillLogLists(self):
        for i in range(0, len(self.enumLogLevelsMap)):
            self.logLevelsList.append(self.enumLogLevelsMap[i])
        
        for i in range(0, len(self.enumlogTypesMap)):
            self.logTypesList.append(self.enumlogTypesMap[i])