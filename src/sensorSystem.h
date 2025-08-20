#ifndef SENSORSYSTEM_H
#define SENSORSYSTEM_H

#include "Sensor.h"
#include <vector>

class SensorSystem {
private:
    std::vector<Sensor> sensors;

public:
    SensorSystem();
    void addSensor(const Sensor& sensor);
    void runSimulation(int cycles);
};

#endif
