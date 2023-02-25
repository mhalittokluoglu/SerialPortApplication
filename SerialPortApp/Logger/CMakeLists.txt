
if(LINUX_SYSTEM)
    message("LOGGER: LINUX SYSTEM IS ACTIVE!\n")
    list(APPEND LOGGER_FILES
    src/SocketClient/Linux/LinuxSocketClient.h
    src/SocketClient/Linux/LinuxSocketClient.cpp
    )
    add_compile_definitions(LINUX_SYSTEM)
endif()

if(WINDOWS_SYSTEM)
    message("LOGGER: WINDOWS SYSTEM IS ACTIVE!\n")
    list(APPEND LOGGER_FILES
    src/SocketClient/Windows/WindowsSocketClient.h
    src/SocketClient/Windows/WindowsSocketClient.cpp
    )
    add_compile_definitions(WINDOWS_SYSTEM)
endif()

if(CONSOLE_LOG)
add_compile_definitions(CONSOLE_LOG)
endif()

if(UDP_LOG)
add_compile_definitions(UDP_LOG)
endif()

add_library(Logger 
${LOGGER_FILES} 
include/Logger.h
src/Logger.cpp
src/SocketClient/ISocketClient.h
src/SocketClient/SocketClientHandler.h
src/SocketClient/SocketClientHandler.cpp
)


target_include_directories(Logger PUBLIC include)
target_include_directories(Logger PRIVATE src)
target_compile_definitions(Logger PUBLIC LOG_ENABLED)