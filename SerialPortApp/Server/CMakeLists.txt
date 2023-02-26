cmake_minimum_required(VERSION 3.16)
project(Server)

file(GLOB_RECURSE SERVER_SRCS *.cpp)
file(GLOB_RECURSE SERVER_HDRS *.h)

add_executable(${PROJECT_NAME}
                ${SERVER_SRCS}
                ${SERVER_HDRS})

target_include_directories(Server PRIVATE src)

add_compile_definitions(COMMAND_READER_DEFAULT)
add_compile_definitions(COMMAND_RECEIVER_DEFAULT)
add_compile_definitions(USER_RECEIVER_DEFAULT)