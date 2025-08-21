#include "sensor_system.h"
#include "observer.h"
#include <iostream>

int main() {
    SensorSystem system;

    // Cargamos sensores desde JSON
    system.loadFromJSON("../sensors.json");

    // Creamos un observador de consola
    ConsoleObserver consoleObs;

    // Registramos el observador en todos los sensores
    system.addObserverToAll(&consoleObs);

    // Ejecutamos la simulación durante 5 ciclos
    auto reports = system.runSimulation(5);

    // Imprimimos resultados
    for (const auto& cycleReport : reports) {
        std::cout << "\n--- Cycle " << cycleReport.cycle << " ---\n";
        for (const auto& sensorReport : cycleReport.sensorReports) {
            std::cout << sensorReport.name << " = " << sensorReport.value;
            if (sensorReport.anomaly) std::cout << " -> ANOMALY DETECTED";
            else std::cout << " -> NORMAL VALUE";
            std::cout << "\n";
        }
    }

    return 0;
}
