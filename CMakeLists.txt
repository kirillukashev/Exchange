cmake_minimum_required(VERSION 3.2)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExchangeCheck main.cpp)

add_subdirectory(Backend)
add_subdirectory(Frontend)

target_link_libraries(ExchangeCheck frontend)
target_link_libraries(ExchangeCheck backend)