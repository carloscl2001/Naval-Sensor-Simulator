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

# --- TESTS DESACTIVADOS ---
# enable_testing()
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})
#
# set(TEST_SOURCES
#     tests/test_sensors.cpp
#     src/Sensor.cpp
#     src/SensorSystem.cpp
# )
#
# add_executable(RunTests ${TEST_SOURCES})
# target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread)
# add_test(NAME RunTests COMMAND RunTests)
