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

    // Crear ventana principal
    QWidget window;
    window.setWindowTitle("Sensor System Monitor");
    window.setStyleSheet("background-color: #f5f5f5;");

    QVBoxLayout* layout = new QVBoxLayout(&window);

    // Crear tabla
    QTableWidget* table = new QTableWidget();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"Sensor", "Value"});
    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setStyleSheet(
        "QTableWidget {"
        "  gridline-color: #ddd;"
        "  font-size: 14px;"
        "}"
        "QHeaderView::section {"
        "  background-color: #e0e0e0;"
        "  font-weight: bold;"
        "}"
    );
    layout->addWidget(table);

    // Crear lista de anomalías
    QListWidget* anomaliesList = new QListWidget();
    anomaliesList->setStyleSheet("font-size: 12px; color: darkred;");
    layout->addWidget(anomaliesList);

    // Sistema de sensores
    SensorSystem system;
    system.loadFromJSON("../sensors.json");

    // Configurar observer Qt
    QtObserver qtObs(table, anomaliesList);
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