cmake_minimum_required(VERSION 3.0)

project(Neural_Network)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
