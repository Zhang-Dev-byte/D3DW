cmake_minimum_required(VERSION 3.15)

file(GLOB TESTS_SRC
    "src/**.h"
    "src/**.cpp"
)

project(D3DWTests)

add_executable(D3DWTests ${TESTS_SRC})

add_definitions(-D_UNICODE)