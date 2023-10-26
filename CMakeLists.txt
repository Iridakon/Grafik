cmake_minimum_required(VERSION 3.24)
project(Grafik)

set(CMAKE_CXX_STANDARD 17)

add_executable(Grafik main.cpp)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/exe/SFML-2.6.0/Lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/exe/SFML-2.6.0/include/SFML)
target_link_libraries(Grafik sfml-system sfml-window sfml-graphics sfml-audio)