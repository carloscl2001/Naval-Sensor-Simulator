/**
 * @file Sensor.cpp
 * @brief Implementación de los métodos de la clase Sensor.
 */

#include "Sensor.h"
#include <cstdlib> // Para std::rand() y std::srand()
#include <ctime>   // Para std::time()

/**
 * @brief Constructor de la clase Sensor.
 * @param n Nombre del sensor.
 * @param minL Límite mínimo aceptable.
 * @param maxL Límite máximo aceptable.
 *
 * Inicializa el generador de números aleatorios para asegurar
 * que los valores generados sean diferentes en cada ejecución.
 */
Sensor::Sensor(const std::string& n, double minL, double maxL)
    : name(n), minLimit(minL), maxLimit(maxL) {
    std::srand(std::time(nullptr));
}

/**
 * @brief Genera un nuevo valor aleatorio para el sensor.
 *
 * Utiliza la función rand() para generar un número aleatorio
 * y lo mapea al rango [minLimit, maxLimit * 1.5].
 */
void Sensor::generateValue() {
    value = minLimit + static_cast<double>(std::rand()) / RAND_MAX * (maxLimit * 1.5 - minLimit);
}

/**
 * @brief Verifica si el valor actual del sensor es una anomalía.
 * @return true si el valor está fuera de los límites [minLimit, maxLimit].
 */
bool Sensor::isAnomaly() const {
    return (value < minLimit || value > maxLimit);
}

/**
 * @brief Obtiene el valor actual del sensor.
 * @return El valor numérico del sensor.
 */
double Sensor::getValue() const {
    return value;
}

/**
 * @brief Obtiene el nombre del sensor.
 * @return El nombre del sensor.
 */
std::string Sensor::getName() const {
    return name;
}