# 🚢 Naval Sensor Simulator

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue)](https://isocpp.org/) 
[![CMake](https://img.shields.io/badge/CMake-3.16+-orange)](https://cmake.org/) 
[![Qt](https://img.shields.io/badge/Qt-6-green)](https://www.qt.io/) 
[![Tests](https://img.shields.io/badge/Tests-GoogleTest-brightgreen)](https://github.com/google/googletest)

**Naval sensor simulator with anomaly detection and Qt visualization.**  

This project is developed in **C++17** and simulates a basic sensor monitoring system (temperature, pressure, speed, etc.).  

The system includes:

- **Qt Widgets GUI** to display sensors in real-time.  
- Anomaly detection with visual highlighting in the table.  
- **Observer pattern** that supports multiple monitoring outputs: console, file, GUI.  
- Simulation cycles with random values, noise, drift, and random failures.  
- **Unit and integration tests** with GoogleTest.  

This project reflects development in **engineering, defense, and naval sectors**, where reliability, thorough testing, and configuration control are essential.

---

## ✨ Current Features

- Sensor simulation with random values, noise, drift and failure probability.  
- Anomaly detection when a value exceeds defined limits.  
- **Real-time visualization using Qt**, highlighting anomalies in the table.  
- Extensible **observer system** (console, file, GUI).  
- Automated unit and integration tests with **Google Test** and **CMake**.  
- Sensor configuration loaded from **JSON** files.  

---


## 📂 Project Structure
```
naval-sensor-simulator/
│── build/
|
│── external/
│ ├── googletest/
│ ├── json/
│ 
│── src/
│ ├── main.cpp
│ ├── observer.h
│ ├── qt_observer.h
│ ├── sensor_system.cpp
│ ├── sensor_system.h
│ ├── sensor.cpp
│ ├── sensor.h
│ ├── simulation_report.h
│
│── tests/
│ ├── unit_test.cpp
│ ├── integration_test.cpp
│
│── sensors.json
│── CMakeLists.txt
│── README.md
```

---

## 🛠 Installation and Build

### Requirements

- **C++17**  
- **Qt6 (Widgets)**  
- **CMake ≥ 3.16**  
- **MinGW** (for Windows)
- GoogleTest (for unit and integration tests)
- nlohmann/json (for reading sensor configuration from JSON files)

### Building on Windows

```powershell
# Go to the build directory
D:
cd D:\Repositories\NavalSensorSimulator\build

# Generate build files
cmake .. -G "MinGW Makefiles"

# Compile the project
mingw32-make
```

### Building on Linux

```powershell
#Navigate to the build directory (create it if it doesn't exist)
mkdir -p ~/NavalSensorSimulator/build
cd ~/NavalSensorSimulator/build

# Generate build files
cmake ..

# Compile the project
make
```
