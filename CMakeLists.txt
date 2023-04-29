cmake_minimum_required(VERSION 3.2)
project(Exchange)

include_directories(${gtest_SOURCE_DIR})
find_package(GTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
#
#add_custom_target(_coverage
#        COMMAND ${CMAKE_COMMAND} -E env "COVERAGE_DIR=${CMAKE_BINARY_DIR}/coverage" "LCOV_INFO=${LCOV_PATH}/lcov.info"
#        ${CMAKE_SOURCE_DIR}/coverage_report.sh "$<TARGET_FILE_DIR:TraderTest>"
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#        )

add_executable(ExchangeCheck
        main.cpp
        StockExchange.cpp
        Starter.cpp)

add_subdirectory(Actions)
add_subdirectory(Company)
add_subdirectory(Order)
add_subdirectory(Trader)
add_subdirectory(tests)

target_link_libraries(ExchangeCheck action)
target_link_libraries(ExchangeCheck company)
target_link_libraries(ExchangeCheck order)
target_link_libraries(ExchangeCheck trader)

target_include_directories(ExchangeCheck PRIVATE ${CMAKE_SOURCE_DIR})

enable_testing()

add_test(Test ${Testing_SOURCE_DIR}/bin/ExchangeTest)

