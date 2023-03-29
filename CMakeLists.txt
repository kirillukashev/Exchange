cmake_minimum_required(VERSION 3.23)
project(Exchange)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExchangeCheck
        main.cpp
        StockExchange.cpp
        Starter.cpp
        Actions/ActionHandler.cpp
        Actions/Action.cpp
        Order/Order.cpp
        Order/OrderActionHandler.cpp
        Order/Type.cpp
        Trader/Trader.cpp
        Trader/TraderActionHandler.cpp
        Company/Stock.cpp
        Company/Company.cpp
        Company/CompanyActionHandler.cpp)
