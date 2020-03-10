cmake_minimum_required(VERSION 3.16)

set(PR_NAME srv)
set(PR_VERS 0.0.0.1)

project(${PR_NAME} VERSION ${PR_VERS} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

set(HEADERS
        ../common/net.hpp
            )

set(SRC
         ../server/main.cpp
         ../common/net.cpp
         )

add_executable(${PROJECT_NAME} ${HEADERS} ${SRC})
