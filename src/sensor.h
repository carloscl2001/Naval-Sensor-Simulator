/**
 * @file sensor.h
 * @brief Definition of the Sensor class.
 *
 * This class simulates a sensor that can generate values,
 * check if they are within an acceptable range, and
 * provide information about itself.
 */

#ifndef SENSOR_H
#define SENSOR_H

#include "observer.h"
#include <string>
#include <vector>

/**
 * @class Sensor
 * @brief A class to represent a data sensor.
 *
 * The Sensor class simulates the behavior of a physical sensor,
 * with the ability to generate random values within a range,
 * detect anomalies, and store properties like its name and limits.
 */
class Sensor {
    private:
        std::string name;          /**< @brief The name of the sensor. */
        double value;              /**< @brief The current value of the sensor. */
        double minLimit;           /**< @brief The lower limit for the sensor's value. */
        double maxLimit;           /**< @brief The upper limit for the sensor's value. */

        double drift;              /**< @brief The sensor's drift value, used to simulate a gradual degradation in accuracy. */
        double noiseLevel;         /**< @brief The noise level for the sensor, used to simulate random fluctuations in sensor readings. (0 to 1). */
        double failureProbability; /**< @brief The probability of sensor failure, used to simulate sensor malfunctions. (0 to 1). */

        std::vector<Observer*> observers; /**< @brief List of observers that will be notified of changes in the sensor's value. */


    public:
        /**
         * @brief Constructor for the Sensor class.
         * @param n The name of the sensor.
         * @param minL The minimum acceptable limit.
         * @param maxL The maximum acceptable limit.
         * @param noise The noise level for sensor readings. Defaults to 0.05.
         * @param failureProb The probability of a sensor failure. Defaults to 0.01.
         */
        Sensor(const std::string& n, double minL, double maxL, double noise = 0.05, double failureProb = 0.01);

        /**
         * @brief Generates a new random value for the sensor.
         *
         * The value generated is a random number between minLimit and maxLimit * 1.5.
         */
        void generateValue();

        /**
         * @brief Checks if the current sensor value is an anomaly.
         * @return true if the value is outside the [minLimit, maxLimit] range,
         * false otherwise.
         */
        bool isAnomaly() const;

        /**
         * @brief Gets the current sensor value.
         * @return The numerical value of the sensor.
         */
        double getValue() const;

        /**
         * @brief Sets the current value of the sensor.
         * @param val The new numerical value to set.
         */
        void setValue(double val);

        /**
         * @brief Gets the name of the sensor.
         * @return The name of the sensor.
         */
        std::string getName() const;

        /**
         * @brief Adds an observer to the sensor's list of observers.
         * @param obs A pointer to the observer to be added.
         */
        void addObserver(Observer* obs);

        /**
         * @brief Notifies all registered observers of a change in the sensor's state.
         */
        void notifyObservers();
};

#endif