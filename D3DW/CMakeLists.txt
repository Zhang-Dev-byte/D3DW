cmake_minimum_required(VERSION 3.15)

file(GLOB D3DW_SRC
    "src/**.h"
    "src/**.cpp"
)

add_library(D3DW ${D3DW_SRC})

add_definitions(-D_UNICODE)