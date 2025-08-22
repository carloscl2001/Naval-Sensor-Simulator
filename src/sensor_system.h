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
    void addSensor(const Sensor& sensor);
    
    std::vector<SimulationReport> runSimulation(int cycles);
    
    void loadFromJSON(const std::string& filename);
    
    // Nuevo método para registrar un observador en todos los sensores
    void addObserverToAll(Observer* obs);

    int getSensorCount() const { return sensors.size(); }
    std::vector<std::string> getSensorNames() const;

    void runSimulationCycle(); // Ejecuta un ciclo y notifica a observadores
};

#endif