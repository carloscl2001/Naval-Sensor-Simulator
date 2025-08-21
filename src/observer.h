#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>


class Observer {
public:
    virtual void update(const std::string& sensorName, double value, bool anomaly) = 0;
    virtual ~Observer() = default;
};

// Ejemplo de observador que imprime en consola
class ConsoleObserver : public Observer {
public:
    void update(const std::string& sensorName, double value, bool anomaly) override {
        if (anomaly) {
            std::cout << "[ALERT] " << sensorName << " value = " << value << " ANOMALY DETECTED!\n";
        }
    }
};

#endif
