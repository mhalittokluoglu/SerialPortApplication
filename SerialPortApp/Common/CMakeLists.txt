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
    include/Commands/CommandProcessorFacade.h
    include/Commands/CommandUtils.h
    include/Commands/DataElements.h
    include/Commands/ICommand.h
    include/Commands/ICommandProcessor.h
    include/SerialConfiguration/ISerialConfigReader.h
    include/SerialConfiguration/ISerialConnection.h
    include/SerialConfiguration/SerialConfigReader.h
    include/SerialConfiguration/SerialConfigReaderFactory.h
    include/SerialConfiguration/SerialConfiguration.h
    include/SerialConfiguration/SerialConnectionFactory.h
    include/CommandManager.h
    include/Constants.h
    include/CRCGenerator.h
    include/EndianController.h
    include/IConnection.h
    include/IManager.h
    src/Commands/Data/DataA.cpp
    src/Commands/ByteStream.cpp
    src/Commands/CommandHeader.cpp
    src/Commands/CommandProcessorFacade.cpp
    src/Commands/CommandUtils.cpp
    src/SerialConfiguration/SerialConfigReader.cpp
    src/SerialConfiguration/SerialConfigReaderFactory.cpp
    src/SerialConfiguration/SerialConnectionFactory.cpp
    src/CommandManager.cpp
    src/CRCGenerator.cpp
    src/EndianController.cpp
)
target_include_directories(Common PUBLIC include)
add_compile_definitions(DEFAULT_CONFIG_READER)
