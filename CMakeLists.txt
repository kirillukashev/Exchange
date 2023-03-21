cmake_minimum_required(VERSION 3.23)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Actions)
include_directories(Company)
include_directories(Trader)

add_executable(Exchange0
        main.cpp)

add_executable(Exchange
        Company/Stock.cpp
        main.cpp)

add_executable(check
        Company/Stock.cpp
        check.cpp)

add_executable(Exchange2
        Trader/Trader.cpp)

add_executable(Exchange3
        Trader/TraderActionHandler.cpp)

add_executable(Exchange4
        StockExchange.cpp)

add_executable(Exchange5
        Starter.cpp)

add_executable(Exchange6
        Actions/Action.cpp)

add_executable(Exchange7
        Actions/ActionHandler.cpp)