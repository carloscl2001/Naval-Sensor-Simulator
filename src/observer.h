/**
 * @file observer.h
 * @brief Definition of the Observer interface and a concrete ConsoleObserver.
 *
 * This file defines the core Observer interface, which is a key component
 * of the Observer design pattern used for decoupling. It also includes
 * an example implementation, the ConsoleObserver, which prints sensor
 * anomaly alerts to the console.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

/**
 * @class Observer
 * @brief The Observer interface for the Observer design pattern.
 *
 * This abstract base class defines the interface that all concrete observers
 * must implement. It allows them to be notified of state changes from a subject
 * (in this case, a Sensor) without the subject needing to know the specific
 * type of the observer.
 */
class Observer {
public:
    /**
     * @brief Notifies the observer of a state change in a sensor.
     * @param sensorName The name of the sensor that has changed.
     * @param value The new numerical value of the sensor.
     * @param anomaly A boolean flag indicating if the new value is an anomaly.
     */
    virtual void update(const std::string& sensorName, double value, bool anomaly) = 0;

    /**
     * @brief Virtual destructor to allow for proper cleanup of derived classes.
     */
    virtual ~Observer() = default;
};

/**
 * @class ConsoleObserver
 * @brief A concrete observer that prints anomaly alerts to the console.
 *
 * This class implements the Observer interface. When a sensor's value
 * is an anomaly, its update() method is called and it prints a formatted
 * alert message to the standard output.
 */
class ConsoleObserver : public Observer {
public:
    /**
     * @brief Prints an alert to the console if an anomaly is detected.
     * @param sensorName The name of the sensor.
     * @param value The value of the sensor.
     * @param anomaly True if the value is an anomaly, false otherwise.
     */
    void update(const std::string& sensorName, double value, bool anomaly) override {
        if (anomaly) {
            std::cout << "[ALERT] " << sensorName << " value = " << value << " ANOMALY DETECTED!\n";
        }
    }
};

#endif