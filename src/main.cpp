/**
 * @file main.cpp
 * @brief Main entry point for the sensor simulation program.
 *
 * This program creates a sensor system and runs a simulation
 * to demonstrate value generation and anomaly detection.
 */

#include "sensor_system.h"

int main() {
    // Creates an instance of the sensor system.
    SensorSystem system;

    // Adds three sensors to the system with their respective names and limits.
    system.addSensor(Sensor("Temperature", 10, 80));
    system.addSensor(Sensor("Pressure", 5, 50));
    system.addSensor(Sensor("Speed", 0, 40));

    // Runs the simulation for 5 cycles.
    system.runSimulation(5);

    return 0;
}