cmake_minimum_required(VERSION 3.5)

project(Generating LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/pizza.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(Generating ${SOURCES})


target_link_libraries(Generating Qt5::Core)
