cmake_minimum_required(VERSION 3.15)
project(ImageScanner)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_executable(ImageScanner image_Scanner.cpp)
target_link_libraries(ImageScanner PRIVATE ${OpenCV_LIBS})