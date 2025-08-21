# 🚢 Naval Sensor Simulator

This project is a **naval sensor simulator** developed in **modern C++**, replicating a basic sensor monitoring system (temperature, pressure, and speed).

---

## ✨ Features
- Simulates sensors with random values.
- Detects anomalies when a value exceeds defined limits.
- Console reporting during simulation cycles.
- Unit and integration testing with **Google Test**.
- Modular project structure with **CMake**.

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
