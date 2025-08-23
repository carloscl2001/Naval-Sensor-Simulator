/**
 * @file sensor.cpp
 * @brief Implementation of the Sensor class methods.
 */

#include "sensor.h"
#include <cstdlib> 
#include <ctime>   
#include <iostream>
#include <random>

/**
 * @brief Constructor for the Sensor class.
 * @param n The name of the sensor.
 * @param minL The minimum acceptable limit.
 * @param maxL The maximum acceptable limit.
 * @param noise The noise level for sensor readings. Defaults to 0.05.
 * @param failureProb The probability of a sensor failure. Defaults to 0.01.
 */
Sensor::Sensor(const std::string& n, double minL, double maxL, double noise, double failureProb)
    : name(n), minLimit(minL), maxLimit(maxL), value(0.0), drift(0.0), noiseLevel(noise), failureProbability(failureProb) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

/**
 * @brief Generates a new random value for the sensor.
 *
 * This method simulates real-world sensor behavior by generating a new value
 * and applying cumulative drift, random noise, and a chance of failure.
 */
void Sensor::generateValue() {
    static std::default_random_engine generator(static_cast<unsigned int>(std::time(nullptr)));
    double mean = (minLimit + maxLimit) / 2.0;
    double stddev = (maxLimit - minLimit) / 6.0;
    std::normal_distribution<double> dist(mean, stddev);

    double newValue = dist(generator);

    // Cumulative drift simulation
    drift += ((std::rand() % 100) / 1000.0);
    newValue += drift;

    // Random noise simulation
    double noise = ((std::rand() % 2000) / 1000.0 - 1.0) * noiseLevel * (maxLimit - minLimit);
    newValue += noise;

    // Random failure event
    double chance = (std::rand() % 1000) / 1000.0;
    if (chance < failureProbability) {
        if (std::rand() % 2) {
            newValue = minLimit - (std::rand() % 20 + 1);
        } else {
            newValue = maxLimit + (std::rand() % 20 + 1);
        }
    }

    value = newValue;
    notifyObservers();
}

/**
 * @brief Checks if the current sensor value is an anomaly.
 * @return True if the value is outside the [minLimit, maxLimit] range,
 * false otherwise.
 */
bool Sensor::isAnomaly() const {
    return (value < minLimit || value > maxLimit);
}

/**
 * @brief Gets the current sensor value.
 * @return The numerical value of the sensor.
 */
double Sensor::getValue() const {
    return value;
}

/**
 * @brief Sets the current value of the sensor.
 * @param val The new numerical value to set.
 */
void Sensor::setValue(double val) {
    value = val;
}

/**
 * @brief Gets the name of the sensor.
 * @return The name of the sensor.
 */
std::string Sensor::getName() const {
    return name;
}

/**
 * @brief Adds an observer to the sensor's list of observers.
 * @param obs A pointer to the observer to be added.
 */
void Sensor::addObserver(Observer* obs) {
    observers.push_back(obs);
}

/**
 * @brief Notifies all registered observers of a change in the sensor's state.
 */
void Sensor::notifyObservers() {
    for (auto* obs : observers) {
        obs->update(name, value, isAnomaly());
    }
}