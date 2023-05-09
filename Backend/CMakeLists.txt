add_subdirectory(Actions)
add_subdirectory(Trader)
add_subdirectory(Order)
add_subdirectory(Company)

add_library(backend ${action} ${trader} ${order} ${company} StockExchange.cpp StockExchange.hpp)
