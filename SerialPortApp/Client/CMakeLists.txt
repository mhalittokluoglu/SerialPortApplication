cmake_minimum_required(VERSION 3.16)
project(Client)

file(GLOB_RECURSE CLIENT_SRCS *.cpp)
file(GLOB_RECURSE CLIENT_HDRS *.h)

add_executable(${PROJECT_NAME}
                ${CLIENT_SRCS}
                ${CLIENT_HDRS})


target_include_directories(Client PRIVATE src)
