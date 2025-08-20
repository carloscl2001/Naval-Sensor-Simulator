# 🚢 Naval Sensor Simulator

Este proyecto es un **simulador de sensores navales** desarrollado en **C++ moderno**, que reproduce un sistema básico de monitorización de sensores (temperatura, presión y velocidad).  

El sistema ejecuta ciclos de simulación, detecta anomalías en las lecturas y genera un reporte por consola. Además, incluye **tests unitarios con Google Test** y una **matriz de pruebas** documentada.  

Este tipo de desarrollo está alineado con entornos de **ingeniería, defensa y sector naval**, donde la fiabilidad del software, las pruebas rigurosas y el control de configuración son esenciales.

---

## ✨ Funcionalidades
- Simulación de sensores con valores aleatorios.
- Detección de anomalías cuando un valor excede los límites definidos.
- Reporte por consola en ciclos de simulación.
- Tests unitarios e integración con **Google Test**.
- **Matriz de pruebas** documentada.
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