# CMake generated Testfile for 
# Source directory: D:/Repositorios/Simulador-de-Sensores-Navales
# Build directory: D:/Repositorios/Simulador-de-Sensores-Navales/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "D:/Repositorios/Simulador-de-Sensores-Navales/build/UnitTests.exe")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "D:/Repositorios/Simulador-de-Sensores-Navales/CMakeLists.txt;55;add_test;D:/Repositorios/Simulador-de-Sensores-Navales/CMakeLists.txt;0;")
add_test(IntegrationTests "D:/Repositorios/Simulador-de-Sensores-Navales/build/IntegrationTests.exe")
set_tests_properties(IntegrationTests PROPERTIES  _BACKTRACE_TRIPLES "D:/Repositorios/Simulador-de-Sensores-Navales/CMakeLists.txt;68;add_test;D:/Repositorios/Simulador-de-Sensores-Navales/CMakeLists.txt;0;")
subdirs("external/googletest")
