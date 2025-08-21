/**
 * @file sensor.cpp
 * @brief Implementation of the Sensor class methods.
 */

#include "sensor.h"
#include <cstdlib> 
#include <ctime>   

Sensor::Sensor(const std::string& n, double minL, double maxL)
    : name(n), minLimit(minL), maxLimit(maxL) {
    // Initializes the random number generator using the current time.
    // This ensures that the generated values are different on each execution.
    std::srand(std::time(nullptr));
}

void Sensor::generateValue() {
    value = minLimit + static_cast<double>(std::rand()) / RAND_MAX * (maxLimit * 1.5 - minLimit);
}

bool Sensor::isAnomaly() const {
    return (value < minLimit || value > maxLimit);
}

double Sensor::getValue() const {
    return value;
}

std::string Sensor::getName() const {
    return name;
}