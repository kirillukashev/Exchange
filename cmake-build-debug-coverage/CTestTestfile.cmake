# CMake generated Testfile for 
# Source directory: /home/lisa/CLionProjects/Exchange
# Build directory: /home/lisa/CLionProjects/Exchange/cmake-build-debug-coverage
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test "/bin/ExchangeTest")
set_tests_properties(Test PROPERTIES  _BACKTRACE_TRIPLES "/home/lisa/CLionProjects/Exchange/CMakeLists.txt;38;add_test;/home/lisa/CLionProjects/Exchange/CMakeLists.txt;0;")
subdirs("Actions")
subdirs("Company")
subdirs("Order")
subdirs("Trader")
subdirs("tests")
