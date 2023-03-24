cmake_minimum_required(VERSION 3.23)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Actions)
include_directories(Company)
include_directories(Trader)

add_executable(Exchange
        Company/Stock.cpp
        main.cpp)

add_executable(check
        Company/Stock.cpp
        Company/Company.cpp
        check.cpp)