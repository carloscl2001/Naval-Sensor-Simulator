/**
 * @file Sensor.h
 * @brief Definición de la clase Sensor.
 *
 * Esta clase simula un sensor que puede generar valores,
 * verificar si están dentro de un rango aceptable y
 * proporcionar información sobre sí mismo.
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <string>

/**
 * @class Sensor
 * @brief Clase para representar un sensor de datos.
 *
 * La clase Sensor permite simular el comportamiento de un sensor físico,
 * con la capacidad de generar valores aleatorios dentro de un rango,
 * detectar anomalías y almacenar propiedades como su nombre y límites.
 */
class Sensor {
private:
    std::string name;     /**< @brief Nombre del sensor. */
    double value;         /**< @brief Valor actual del sensor. */
    double minLimit;      /**< @brief Límite inferior para el valor del sensor. */
    double maxLimit;      /**< @brief Límite superior para el valor del sensor. */

public:
    /**
     * @brief Constructor de la clase Sensor.
     * @param n Nombre del sensor.
     * @param minL Límite mínimo aceptable.
     * @param maxL Límite máximo aceptable.
     */
    Sensor(const std::string& n, double minL, double maxL);

    /**
     * @brief Genera un nuevo valor aleatorio para el sensor.
     *
     * El valor generado es un número aleatorio entre minLimit y maxLimit * 1.5.
     */
    void generateValue();

    /**
     * @brief Verifica si el valor actual del sensor es una anomalía.
     * @return true si el valor está fuera de los límites [minLimit, maxLimit],
     * false en caso contrario.
     */
    bool isAnomaly() const;

    /**
     * @brief Obtiene el valor actual del sensor.
     * @return El valor numérico del sensor.
     */
    double getValue() const;

    /**
     * @brief Obtiene el nombre del sensor.
     * @return El nombre del sensor.
     */
    std::string getName() const;
};

#endif