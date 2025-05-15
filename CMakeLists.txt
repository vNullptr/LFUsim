cmake_minimum_required(VERSION 3.30)
project(LFUsim C)

set(CMAKE_C_STANDARD 11)

add_executable(LFUsim main.c)

add_subdirectory(src)

target_link_libraries(LFUsim
    LFUlib
)
