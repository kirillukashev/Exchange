cmake_minimum_required(VERSION 3.23)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Actions)
include_directories(Company)
include_directories(Trader)
include_directories(Order)

add_executable(ExchangeCheck
        main.cpp
        StockExchange.cpp
        Starter.cpp
        Order/Order.cpp
        Order/OrderActionHandler.cpp
        Order/Transaction.cpp
        Order/Type.cpp
        Trader/Trader.cpp
        Actions/Action.cpp
        Actions/ActionHandler.cpp
        Trader/TraderActionHandler.cpp
        Company/Stock.cpp
        Company/Company.cpp
        Company/CompanyActionHandler.cpp)