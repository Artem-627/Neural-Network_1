cmake_minimum_required(VERSION 3.0)

project(Neural_Network)

set(CMAKE_CXX_STANDARD 11)

# set(SOURCES
#     Source/Neuron.cpp
#     main.cpp
# )

include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME}
    Source/Neuron.cpp
    main.cpp
)
