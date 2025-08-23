/**
 * @file simulation_report.h
 * @brief Defines data structures for simulation reports.
 *
 * This file contains the definitions for the `SensorReport` and `SimulationReport`
 * structs. These structures are used to organize and store the output data
 * from each simulation cycle, including sensor values and anomaly status.
 */

#ifndef SIMULATION_REPORT_H
#define SIMULATION_REPORT_H

#include <string>
#include <vector>

/**
 * @struct SensorReport
 * @brief A structure to hold data for a single sensor's reading.
 *
 * This struct encapsulates the key information for a single sensor's state at
 * a specific moment in the simulation, making it easy to store and retrieve
 * reports on a per-sensor basis.
 */
struct SensorReport {
    std::string name;   /**< @brief The name of the sensor. */
    double value;       /**< @brief The value of the sensor at the time of the report. */
    bool anomaly;       /**< @brief A flag indicating whether the sensor's value was an anomaly. */
};

/**
 * @struct SimulationReport
 * @brief A structure to hold data for a complete simulation cycle.
 *
 * This struct aggregates the data from all sensors for a single simulation
 * cycle, providing a comprehensive snapshot of the system's state at that time.
 */
struct SimulationReport {
    int cycle;                      /**< @brief The cycle number of the simulation. */
    std::vector<SensorReport> sensorReports; /**< @brief A vector containing the reports for all sensors in the cycle. */
};

#endif