// Métodos de la clase Sensor
#include "Sensor.h"
#include <cstdlib>
#include <ctime>

//Constructor de la clase Sensor
Sensor::Sensor(const std::string& n, double minL, double maxL)
    : name(n), minLimit(minL), maxLimit(maxL) {
    std::srand(std::time(nullptr));
}

// Método para simular la lectura del sensor
void Sensor::generateValue() {
    value = minLimit + static_cast<double>(std::rand()) / RAND_MAX * (maxLimit * 1.5);
}

// Método para verificar si el valor del sensor es una anomalía
bool Sensor::isAnomaly() const {
    return (value < minLimit || value > maxLimit);
}

// Métodos para obtener el valor y el nombre del sensor
double Sensor::getValue() const {
    return value;
}

// Método para obtener el nombre del sensor
std::string Sensor::getName() const {
    return name;
}
