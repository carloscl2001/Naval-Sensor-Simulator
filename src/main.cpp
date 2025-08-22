#include <QApplication>
#include <QTableWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>
#include <QHeaderView>  
#include "sensor_system.h"
#include "qt_observer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Estilo global
    app.setStyleSheet(
        "QWidget { background-color: #e6f2ff; }"
        "QTableWidget { background-color: white; border: 1px solid #ccc; }"
        "QHeaderView::section { background-color: #007acc; color: white; }"
        "QListWidget { background-color: #f9f9f9; border: 1px solid #ccc; }"
    );

    // Crear ventana principal
    QWidget window;
    window.setWindowTitle("Sensor System Monitor");
    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->setContentsMargins(10,10,10,10);
    layout->setSpacing(15);

    // Crear tabla
    QTableWidget* table = new QTableWidget();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"Sensor", "Value"});
    table->setAlternatingRowColors(true);
    table->horizontalHeader()->setStretchLastSection(true);
    layout->addWidget(table);

    // Crear lista de anomalías
    QListWidget* anomalyList = new QListWidget();
    layout->addWidget(anomalyList);

    // Sistema de sensores
    SensorSystem system;
    system.loadFromJSON("../sensors.json");

    // Configurar observer Qt
    QtObserver qtObs(table, anomalyList);
    table->setRowCount(system.getSensorCount());
    int row = 0;
    for (auto& sensorName : system.getSensorNames()) {
        qtObs.registerSensor(sensorName, row++);
    }
    system.addObserverToAll(&qtObs);

    // Simulación periódica
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        system.runSimulationCycle();
    });
    timer.start(1000);

    window.show();
    return app.exec();
}
