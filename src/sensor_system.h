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
#include "simulation_report.h"
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
     * @brief Adds a new sensor to the system.
     * @param sensor The sensor object to add.
     */
    void addSensor(const Sensor& sensor);
    
    /**
     * @brief Runs a simulation for a specified number of cycles.
     * @param cycles The number of cycles to run the simulation.
     * @return A vector of SimulationReport objects, one for each cycle.
     */
    std::vector<SimulationReport> runSimulation(int cycles);
    
    /**
     * @brief Loads sensor configurations from a JSON file.
     * @param filename The path to the JSON configuration file.
     */
    void loadFromJSON(const std::string& filename);
    
    /**
     * @brief Adds a single observer to all sensors in the system.
     * @param obs A pointer to the observer to be added.
     */
    void addObserverToAll(Observer* obs);

    /**
     * @brief Gets the total number of sensors in the system.
     * @return The count of sensors.
     */
    int getSensorCount() const { return sensors.size(); }

    /**
     * @brief Gets the names of all sensors in the system.
     * @return A vector of strings containing the names of the sensors.
     */
    std::vector<std::string> getSensorNames() const;

    /**
     * @brief Executes a single simulation cycle.
     *
     * This method runs one data generation cycle for all sensors and
     * notifies their registered observers.
     */
    void runSimulationCycle();
};

#endif