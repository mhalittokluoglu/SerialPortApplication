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

add_library(Common
${COMMON_FILES}
include/SerialConfiguration/SerialConfigReader.h
include/SerialConfiguration/SerialConfiguration.h
include/SerialConfiguration/SerialConnectionFactory.h
include/EndianController.h
include/SerialConfiguration/ISerialConnection.h
include/CRCGenerator.h
include/Commands/BaseCommand.h
include/Commands/ByteStream.h
include/Commands/ICommand.h
src/SerialConfiguration/SerialConfigReader.cpp
src/SerialConfiguration/SerialConnectionFactory.cpp
src/EndianController.cpp
src/CRCGenerator.cpp
src/Commands/BaseCommand.cpp
src/Commands/ByteStream.cpp
)
target_include_directories(Common PUBLIC include)
