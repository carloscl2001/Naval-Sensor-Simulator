#include <QApplication>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>
#include "sensor_system.h"
#include "qt_observer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear ventana principal
    QWidget window;
    window.setWindowTitle("Sensor System Monitor");
    QVBoxLayout* layout = new QVBoxLayout(&window);

    // Crear tabla
    QTableWidget* table = new QTableWidget();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"Sensor", "Value"});
    layout->addWidget(table);

    // Sistema de sensores
    SensorSystem system;
    system.loadFromJSON("../sensors.json");

    // Configurar observer Qt
    QtObserver qtObs(table);
    table->setRowCount(system.getSensorCount());
    int row = 0;
    for (auto& sensorName : system.getSensorNames()) {
        qtObs.registerSensor(sensorName, row++);
    }
    system.addObserverToAll(&qtObs);

    // Simulación periódica
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        system.runSimulationCycle(); // Método que solo ejecuta un ciclo
    });
    timer.start(1000); // cada 1 segundo

    window.show();
    return app.exec();
}
