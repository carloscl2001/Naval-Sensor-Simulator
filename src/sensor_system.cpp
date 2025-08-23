#include "sensor_system.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

/**
 * @brief Adds a new sensor to the system.
 * @param sensor The sensor object to add.
 */
void SensorSystem::addSensor(const Sensor& sensor) {
    sensors.push_back(sensor);
}

/**
 * @brief Runs a complete simulation for a specified number of cycles.
 * * This method simulates the sensor system's operation over time.
 * For each cycle, it generates new values for all sensors and
 * records a report of their status and any anomalies.
 * * @param cycles The total number of simulation cycles to run.
 * @return A vector containing a simulation report for each cycle.
 */
std::vector<SimulationReport> SensorSystem::runSimulation(int cycles) {
    std::vector<SimulationReport> reports;

    for (int i = 0; i < cycles; ++i) {
        SimulationReport report;
        report.cycle = i + 1;

        for (auto& sensor : sensors) {
            sensor.generateValue();
            report.sensorReports.push_back({sensor.getName(), sensor.getValue(), sensor.isAnomaly()});
        }

        reports.push_back(report);
    }
    return reports;
}

/**
 * @brief Loads sensor configurations from a JSON file.
 * * This method reads a JSON file, parses its contents, and creates
 * Sensor objects based on the provided configuration. It handles
 * default values for noise and failure probability if they are not
 * specified in the file.
 * * @param filename The path to the JSON configuration file.
 */
void SensorSystem::loadFromJSON(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir archivo JSON\n";
        return;
    }

    nlohmann::json j;
    file >> j;

    for (auto& s : j["sensors"]) {
        std::string name = s["name"];
        double min = s["min"];
        double max = s["max"];
        double noise = s.value("noise", 0.05);
        double failProb = s.value("failureProbability", 0.05);

        addSensor(Sensor(name, min, max, noise, failProb));
    }
}

/**
 * @brief Adds a single observer to all sensors managed by the system.
 * * This is a utility method to simplify the process of registering
 * a single observer (e.g., a GUI, console, or file reporter) to all
 * sensors at once, implementing the Observer Pattern.
 * * @param obs A pointer to the observer to be added.
 */
void SensorSystem::addObserverToAll(Observer* obs) {
    for (auto& sensor : sensors) {
        sensor.addObserver(obs);
    }
}

/**
 * @brief Gets the names of all sensors in the system.
 * @return A vector of strings containing the names of the sensors.
 */
std::vector<std::string> SensorSystem::getSensorNames() const {
    std::vector<std::string> names;
    for (const auto& s : sensors) names.push_back(s.getName());
    return names;
}

/**
 * @brief Executes a single simulation cycle.
 * * This method triggers the generation of new values for each sensor.
 * It does not create a report; its primary purpose is to update
 * the sensor values so they can be read by their observers.
 */
void SensorSystem::runSimulationCycle() {
    for (auto& sensor : sensors) {
        sensor.generateValue();
    }
}