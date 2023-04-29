include_directories(${GTEST_INCLUDE_DIRS})

add_executable(ExchangeTest main_test.cpp ExchangeTest.cpp
        ../StockExchange.cpp
        ../Starter.cpp
        ../Actions/ActionHandler.cpp
        ../Actions/Action.cpp
        ../Order/Order.cpp
        ../Order/OrderActionHandler.cpp
        ../Order/Type.cpp
        ../Trader/Trader.cpp
        ../Trader/TraderActionHandler.cpp
        ../Company/Stock.cpp
        ../Company/Company.cpp
        ../Company/CompanyActionHandler.cpp
        ../Starter.cpp)
#target_link_libraries(ExchangeTest action)
#target_link_libraries(ExchangeTest company)
#target_link_libraries(ExchangeTest order)
#target_link_libraries(ExchangeTest trader)

target_link_libraries(ExchangeTest ${GTEST_LIBRARIES})