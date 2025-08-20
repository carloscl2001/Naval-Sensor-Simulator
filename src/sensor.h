//Clase Sensor
#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class Sensor {
    private:
        std::string name;
        double value;
        double minLimit;
        double maxLimit;

    public:
        Sensor(const std::string& n, double minL, double maxL);
        void generateValue();   // Simulación de lectura
        bool isAnomaly() const;
        double getValue() const;
        std::string getName() const;
};

#endif
