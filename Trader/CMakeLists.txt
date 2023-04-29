project(trader)
#set(Trader-source-files "${PROJECT_SOURCE_DIR}/Trader.cpp" "${PROJECT_SOURCE_DIR}/TraderActionHandler.cpp" CACHE INTERNAL "")
add_library(trader SHARED Trader.cpp TraderActionHandler.cpp Trader.hpp TraderActionHandler.hpp)