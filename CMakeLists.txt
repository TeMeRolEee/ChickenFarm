cmake_minimum_required(VERSION 3.12)
project(ChickenFarm)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets HINTS ~/Qt/5.11.1/gcc_64/)

add_executable(ChickenFarm main.cpp Chicken.cpp Farm.cpp)

target_link_libraries(ChickenFarm Qt5::Widgets)