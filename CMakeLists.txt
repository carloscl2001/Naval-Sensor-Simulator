cmake_minimum_required(VERSION 3.16)
project(NavalSensorSimulator)

# ----------------------------
# General configuration
# ----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ----------------------------
# Qt configuration
# ----------------------------
# Ajusta esta ruta a tu instalación de Qt
set(CMAKE_PREFIX_PATH "D:/Qt/6.5.2/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ----------------------------
# Include directories
# ----------------------------
include_directories(src)
include_directories(external/googletest/googletest/include)
include_directories(external/json)

# ----------------------------
# Project source files
# ----------------------------
set(SOURCES
    src/main.cpp
    src/sensor.cpp
    src/sensor_system.cpp
)

# Main executable (con Qt)
add_executable(NavalSimulator ${SOURCES})
target_link_libraries(NavalSimulator Qt6::Widgets)

# ----------------------------
# GoogleTest
# ----------------------------
enable_testing()
add_subdirectory(external/googletest)

# ----------------------------
# Unit Tests
# ----------------------------
set(UNIT_TEST_SOURCES
    tests/unit_test.cpp
    src/sensor.cpp
    src/sensor_system.cpp
)

add_executable(UnitTests ${UNIT_TEST_SOURCES})
target_link_libraries(UnitTests gtest gtest_main)
add_test(NAME UnitTests COMMAND UnitTests)

# ----------------------------
# Integration Tests
# ----------------------------
set(INTEGRATION_TEST_SOURCES
    tests/integration_test.cpp
    src/sensor.cpp
    src/sensor_system.cpp
)

add_executable(IntegrationTests ${INTEGRATION_TEST_SOURCES})
target_link_libraries(IntegrationTests gtest gtest_main)
add_test(NAME IntegrationTests COMMAND IntegrationTests)
