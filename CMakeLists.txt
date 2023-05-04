cmake_minimum_required(VERSION 3.2)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExchangeCheck
        main.cpp
        StockExchange.cpp
        Frontend/Starter.cpp)

add_subdirectory(Actions)
add_subdirectory(Company)
add_subdirectory(Order)
add_subdirectory(Trader)
add_subdirectory(Frontend)

target_link_libraries(ExchangeCheck action)
target_link_libraries(ExchangeCheck company)
target_link_libraries(ExchangeCheck order)
target_link_libraries(ExchangeCheck trader)
target_link_libraries(ExchangeCheck frontend)