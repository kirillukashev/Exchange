#!/bin/bash

mkdir -p "$COVERAGE_DIR"
lcov --capture --directory "$1" --rc lcov_branch_coverage=1 --output-file "$COVERAGE_DIR/coverage.info"
lcov --remove "$COVERAGE_DIR/coverage.info" \
    '/usr/include/*' \
    '*_test.cpp' \
    '*_unittest.cpp' \
    '*_config.cpp' \
    '*_fixture.cpp' \
    '*_mock.cpp' \
    '/googletest/*' \
    -o "$COVERAGE_DIR/coverage.info" --rc lcov_branch_coverage=1
lcov --list "$COVERAGE_DIR/coverage.info" && genhtml -o "$COVERAGE_DIR" "$COVERAGE_DIR/coverage.info" --branch-coverage
lcov --rc lcov_branch_coverage=1 --directory "$1" --zerocounters