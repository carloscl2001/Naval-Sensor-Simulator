/**
 * @file sensor_system.h
 * @brief Definition of the SensorSystem class.
 *
 * This class manages a collection of sensors, allowing
 * for the simulation of their operation and detection of anomalies.
 */

#ifndef SENSORSYSTEM_H
#define SENSORSYSTEM_H

#include "sensor.h"
#include <vector>

/**
 * @class SensorSystem
 * @brief A class to manage a collection of sensors.
 *
 * The SensorSystem class administers a group of Sensor objects,
 * providing functionality to add new sensors and
 * run a data reading simulation for a specified number of cycles.
 */
class SensorSystem {
private:
    /**
     * @brief A vector of Sensor objects to store the sensors
     * that are part of the system.
     */
    std::vector<Sensor> sensors;

public:
    /**
     * @brief Default constructor for the SensorSystem class.
     *
     * Initializes an empty sensor system.
     */
    SensorSystem();

    /**
     * @brief Adds a sensor to the system.
     * @param sensor The Sensor object to be added.
     */
    void addSensor(const Sensor& sensor);

    /**
     * @brief Runs a data reading simulation for all sensors.
     * @param cycles The number of simulation cycles to run.
     *
     * During each cycle, every sensor generates a new value, prints it
     * to the console, and checks for an anomaly.
     */
    void runSimulation(int cycles);
};

#endif