cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(ConsoleDrawingTool)

file(GLOB PROJECT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/ConsoleDrawingTool/*.cpp")

add_executable(ConsoleDrawingTool "${PROJECT_SOURCE_FILES}")

target_include_directories(ConsoleDrawingTool PRIVATE "${PROJECT_SOURCE_DIR}/ConsoleDrawingTool")