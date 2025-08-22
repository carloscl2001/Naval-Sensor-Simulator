# 🚢 Naval Sensor Simulator

**Naval sensor simulator with anomaly detection and Qt visualization.**  

This project is developed in **C++17** and simulates a basic sensor monitoring system (temperature, pressure, speed, etc.).  

The system now includes:

- **Qt Widgets GUI** to display sensors in real-time.  
- Anomaly detection with visual highlighting in the table.  
- **Observer pattern** that supports multiple monitoring outputs: console, file, GUI.  
- Simulation cycles with random values, noise, drift, and random failures.  
- **Unit and integration tests** with GoogleTest.  

This project reflects development in **engineering, defense, and naval sectors**, where reliability, thorough testing, and configuration control are essential.

---

## ✨ Current Features

- Sensor simulation with random values, noise, and cumulative drift.  
- Anomaly detection when a value exceeds defined limits.  
- **Real-time visualization using Qt**, highlighting anomalies in the table.  
- Extensible **observer system** (console, file, GUI).  
- Automated unit and integration tests with **Google Test** and **CMake**.  
- Sensor configuration loaded from **JSON** files.  

---


## 📂 Project Structure
```
naval-sensor-simulator/
│── src/
│ ├── main.cpp
│ ├── observer.h
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
