#ifndef SIMULATION_REPORT_H
#define SIMULATION_REPORT_H

#include <string>
#include <vector>

struct SensorReport {
    std::string name;
    double value;
    bool anomaly;
};

struct SimulationReport {
    int cycle;
    std::vector<SensorReport> sensorReports;
};

#endif
