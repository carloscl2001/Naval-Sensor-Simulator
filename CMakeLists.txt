cmake_minimum_required(VERSION 3.10)
project(NavalSensorSimulator)

# Usar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir carpeta src
include_directories(src)

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/sensor.cpp
    src/sensor_system.cpp
)

# Crear ejecutable principal
add_executable(NavalSimulator ${SOURCES})

# --- TESTS ---
enable_testing()

# Incluir GoogleTest como subdirectorio
add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

set(TEST_SOURCES
    tests/test_sensors.cpp
    src/sensor.cpp
    src/sensor_system.cpp
)

add_executable(RunTests ${TEST_SOURCES})

# Linkear con GTest (importante para Windows)
target_link_libraries(RunTests gtest gtest_main)

add_test(NAME RunTests COMMAND RunTests)
