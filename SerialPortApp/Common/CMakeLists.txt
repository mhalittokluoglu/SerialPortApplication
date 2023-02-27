if(LINUX_SYSTEM)
    message("COMMON: LINUX SYSTEM IS ACTIVE!\n")
    list(APPEND COMMON_FILES
    src/SerialConfiguration/LinuxSerialConnection.cpp
    src/SerialConfiguration/LinuxSerialConnection.h
    )
    add_compile_definitions(LINUX_SYSTEM)
endif()


if(WINDOWS_SYSTEM)
    message("COMMON: WINDOWS SYSTEM IS ACTIVE!\n")
    list(APPEND COMMON_FILES
    src/SerialConfiguration/WindowsSerialConnection.h
    src/SerialConfiguration/WindowsSerialConnection.cpp
    )
    add_compile_definitions(WINDOWS_SYSTEM)
endif()


add_library(Common ${COMMON_FILES}
    include/Commands/Data/DataA.h
    include/Commands/ByteStream.h
    include/Commands/CommandHeader.h
    include/Commands/CommandReceiverFacade.h
    include/Commands/DataElements.h
    include/Commands/FirstCommand.h
    include/Commands/ICommand.h
    include/Commands/ICommandProcessor.h
    include/Commands/InvalidCommand.h
    include/Commands/InvalidRequestCommand.h
    include/Commands/SecondCommand.h
    include/SerialConfiguration/ISerialConfigReader.h
    include/SerialConfiguration/ISerialConnection.h
    include/SerialConfiguration/SerialConfigReader.h
    include/SerialConfiguration/SerialConfigReaderFactory.h
    include/SerialConfiguration/SerialConfiguration.h
    include/SerialConfiguration/SerialConnectionFactory.h
    include/CRCGenerator.h
    include/EndianController.h
    include/IManager.h
    src/Commands/Data/DataA.cpp
    src/Commands/ByteStream.cpp
    src/Commands/CommandHeader.cpp
    src/Commands/DataElements.cpp
    src/Commands/FirstCommand.cpp
    src/Commands/InvalidCommand.cpp
    src/Commands/InvalidRequestCommand.cpp
    src/Commands/SecondCommand.cpp
    src/SerialConfiguration/SerialConfigReader.cpp
    src/SerialConfiguration/SerialConfigReaderFactory.cpp
    src/SerialConfiguration/SerialConnectionFactory.cpp
    src/CRCGenerator.cpp
    src/EndianController.cpp
)
target_include_directories(Common PUBLIC include)
add_compile_definitions(DEFAULT_CONFIG_READER)
