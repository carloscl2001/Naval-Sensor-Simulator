/**
 * @file sensor_system.cpp
 * @brief Implementation of the SensorSystem class methods.
 */

#include "sensor_system.h"
#include <iostream>

// The constructor doesn't need additional documentation here since its purpose is simple and described in the .h file.
SensorSystem::SensorSystem() {}

// The addSensor method doesn't require extra documentation as its implementation is self-explanatory.
void SensorSystem::addSensor(const Sensor& sensor) {
    sensors.push_back(sensor);
}

/**
 * @brief Runs a data reading simulation for all sensors.
 * @param cycles The number of simulation cycles to run.
 *
 * This method iterates for a predefined number of cycles. In each cycle,
 * it loops through all the sensors, calls their `generateValue` method,
 * and prints the value along with an alert if an anomaly is detected.
 */
void SensorSystem::runSimulation(int cycles) {
    for (int i = 0; i < cycles; i++) {
        std::cout << "\n---------------| Cycle " << i + 1 << " |---------------\n";
        for (auto& sensor : sensors) {
            sensor.generateValue();
            std::cout << sensor.getName() << " = " << sensor.getValue() << "-> ";
            if (sensor.isAnomaly()) {
                std::cout <<"ANOMALY DETECTED";
            }else {
                std::cout << "NORMAL VALUE";
            }
            std::cout << "\n";
        }
        std::cout << "-----------------------------------------\n";
    }
}