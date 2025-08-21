/**
 * @file sensor.cpp
 * @brief Implementation of the Sensor class methods.
 */

#include "sensor.h"
#include <cstdlib> 
#include <ctime>   
#include <iostream>
#include <random>

Sensor::Sensor(const std::string& n, double minL, double maxL, double noise, double failureProb)
    : name(n), minLimit(minL), maxLimit(maxL), value(0.0), drift(0.0), noiseLevel(noise), failureProbability(failureProb) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Sensor::generateValue() {
    static std::default_random_engine generator(static_cast<unsigned int>(std::time(nullptr)));
    double mean = (minLimit + maxLimit) / 2.0;
    double stddev = (maxLimit - minLimit) / 6.0;
    std::normal_distribution<double> dist(mean, stddev);

    double newValue = dist(generator);

    // Drift acumulativo
    drift += ((std::rand() % 100) / 1000.0);
    newValue += drift;

    // Ruido aleatorio
    double noise = ((std::rand() % 2000) / 1000.0 - 1.0) * noiseLevel * (maxLimit - minLimit);
    newValue += noise;

    // Evento aleatorio de fallo
    double chance = (std::rand() % 1000) / 1000.0;
    if (chance < failureProbability) {
        if (std::rand() % 2) newValue = minLimit - (std::rand() % 20 + 1);
        else newValue = maxLimit + (std::rand() % 20 + 1);
    }

    value = newValue;
    notifyObservers();
}

bool Sensor::isAnomaly() const {
    return (value < minLimit || value > maxLimit);
}

double Sensor::getValue() const {
    return value;
}

void Sensor::setValue(double val) {
    value = val;
}

std::string Sensor::getName() const {
    return name;
}

void Sensor::addObserver(Observer* obs) {
    observers.push_back(obs);
}

void Sensor::notifyObservers() {
    for (auto* obs : observers) {
        obs->update(name, value, isAnomaly());
    }
}