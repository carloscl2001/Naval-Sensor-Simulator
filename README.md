# 🚢 Naval Sensor Simulator

Este proyecto es un **simulador de sensores navales** desarrollado en **C++ moderno**, que reproduce un sistema básico de monitorización de sensores (temperatura, presión y velocidad).  

---

## ✨ Funcionalidades
- Simulación de sensores con valores aleatorios.
- Detección de anomalías cuando un valor excede los límites definidos.
- Reporte por consola en ciclos de simulación.
- Tests unitarios e integración con **Google Test**.
- Proyecto modular con **CMake**.

---

## 📂 Estructura del proyecto
naval-sensor-simulator/
│── src/
│ ├── main.cpp
│ ├── Sensor.h
│ ├── Sensor.cpp
│ ├── SensorSystem.h
│ ├── SensorSystem.cpp
│
│── tests/
│ ├── test_sensors.cpp
│
│── docs/
│ ├── test_matrix.md
│
│── CMakeLists.txt
│── README.md
