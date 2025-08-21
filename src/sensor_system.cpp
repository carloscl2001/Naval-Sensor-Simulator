#include "sensor_system.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void SensorSystem::addSensor(const Sensor& sensor) {
    sensors.push_back(sensor);
}

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


void SensorSystem::addObserverToAll(Observer* obs) {
    for (auto& sensor : sensors) {
        sensor.addObserver(obs);
    }
}