if(LINUX_SYSTEM)
    message("COMMON: LINUX SYSTEM IS ACTIVE!\n")
    list(APPEND COMMON_FILES
    src/LinuxSerialConnection.cpp
    src/LinuxSerialConnection.h
    )
    add_compile_definitions(LINUX_SYSTEM)
endif()


if(WINDOWS_SYSTEM)
    message("COMMON: WINDOWS SYSTEM IS ACTIVE!\n")
    list(APPEND COMMON_FILES
    src/WindowsSerialConnection.h
    src/WindowsSerialConnection.cpp
    )
    add_compile_definitions(WINDOWS_SYSTEM)
endif()

add_library(Common
${COMMON_FILES}
include/SerialConfigReader.h
include/SerialConfiguration.h
include/SerialConnectionFactory.h
include/EndianController.h
include/ISerialConnection.h
src/SerialConfigReader.cpp
src/SerialConnectionFactory.cpp
src/EndianController.cpp
)
target_include_directories(Common PUBLIC include)
