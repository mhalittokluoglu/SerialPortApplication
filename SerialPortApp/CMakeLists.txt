cmake_minimum_required(VERSION 3.16)

project (SerialPortApp)

option(LOG_ENABLED "Log Enabled Option" ON)
option(LINUX_SYSTEM "Linux Build Option" OFF)
option(WINDOWS_SYSTEM "Windows Build Option" ON)

add_subdirectory(Server)
add_subdirectory(Client)
if (LOG_ENABLED)
    option(CONSOLE_LOG "Console Log Option" OFF)
    option(UDP_LOG "Upd Log Option" OFF)
    add_subdirectory(Logger)
endif()
add_subdirectory(Common)

if (LOG_ENABLED)
    target_include_directories(Server PUBLIC Logger/include)
    target_include_directories(Client PUBLIC Logger/include)
    target_include_directories(Common PUBLIC Logger/include)
    target_link_libraries(Server Logger)
    target_link_libraries(Client Logger)
    target_link_libraries(Common Logger)
endif()

target_include_directories(Server PUBLIC Common/include)
target_include_directories(Client PUBLIC Common/include)

target_link_libraries(Server Common)
target_link_libraries(Client Common)
