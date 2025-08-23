/**
 * @file main.cpp
 * @brief Main entry point for the Naval Sensor Simulator application.
 *
 * This file sets up the Qt-based graphical user interface (GUI) for the sensor
 * monitoring system. It initializes the main window, creates the table and
 * anomaly list widgets, loads sensor configurations from a JSON file, and
 * establishes a real-time simulation loop using a QTimer.
 */

#include <QApplication>
#include <QTableWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>
#include <QHeaderView>  
#include "sensor_system.h"
#include "qt_observer.h"

/**
 * @brief The main function for the application.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return The application's exit code.
 *
 * This function initializes the Qt application, sets up the main window and
 * its widgets, and configures the SensorSystem to display real-time data
 * through the QtObserver.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main application window
    QWidget window;
    window.setWindowTitle("Sensor System Monitor");
    window.resize(400, 600);
    window.setStyleSheet("background-color: #f5f5f5;");

    QVBoxLayout* layout = new QVBoxLayout(&window);

    // Create and configure the sensor data table
    QTableWidget* table = new QTableWidget();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"Sensor", "Value"});
    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setStyleSheet(
        "QTableWidget {"
        "  gridline-color: #ddd;"
        "  font-size: 14px;"
        "}"
        "QHeaderView::section {"
        "  background-color: #e0e0e0;"
        "  font-weight: bold;"
        "}"
    );
    layout->addWidget(table);

    // Create and configure the anomaly list widget
    QListWidget* anomaliesList = new QListWidget();
    anomaliesList->setStyleSheet("font-size: 12px; color: darkred;");
    layout->addWidget(anomaliesList);

    // Initialize the sensor system and load configuration
    SensorSystem system;
    system.loadFromJSON("../sensors.json");

    // Set up the Qt observer to update the GUI
    QtObserver qtObs(table, anomaliesList);
    table->setRowCount(system.getSensorCount());
    int row = 0;
    for (auto& sensorName : system.getSensorNames()) {
        qtObs.registerSensor(sensorName, row++);
    }
    system.addObserverToAll(&qtObs);

    // Start the real-time simulation loop using a timer
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        system.runSimulationCycle();
    });
    timer.start(1000); // 1000 ms = 1 second

    window.show();
    return app.exec();
}