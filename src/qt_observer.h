/**
 * @file qt_observer.h
 * @brief Definition of the QtObserver class.
 *
 * This class serves as a concrete observer in the Observer Pattern,
 * specifically designed to update a Qt-based graphical user interface (GUI).
 * It visualizes real-time sensor data in a QTableWidget and logs anomalies
 * in a QListWidget.
 */

#ifndef QT_OBSERVER_H
#define QT_OBSERVER_H

#include "observer.h"
#include <QTableWidget>
#include <QListWidget>
#include <QString>
#include <QColor>
#include <unordered_map>

/**
 * @class QtObserver
 * @brief A concrete observer for visualizing sensor data in a Qt GUI.
 *
 * This class implements the Observer interface to receive updates from
 * a Sensor and displays the data in a Qt QTableWidget. It also highlights
 * anomalies with a red background and logs them to a QListWidget.
 */
class QtObserver : public Observer {
private:
    QTableWidget* table;              /**< @brief Pointer to the QTableWidget used for displaying sensor data. */
    QListWidget* anomaliesList;       /**< @brief Pointer to the QListWidget used for logging anomalies. */
    std::unordered_map<std::string, int> rowMap; /**< @brief Map to quickly find the row index for a given sensor name. */

public:
    /**
     * @brief Constructor for the QtObserver class.
     * @param tableWidget A pointer to the QTableWidget that will display the sensor data.
     * @param anomaliesWidget A pointer to the QListWidget that will log anomalies.
     */
    QtObserver(QTableWidget* tableWidget, QListWidget* anomaliesWidget)
        : table(tableWidget), anomaliesList(anomaliesWidget) {}

    /**
     * @brief Registers a sensor with the observer.
     * @param name The name of the sensor to register.
     * @param row The row index in the QTableWidget where the sensor's data will be displayed.
     *
     * This method initializes the table row for a new sensor by setting its name.
     */
    void registerSensor(const std::string& name, int row) {
        rowMap[name] = row;
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(name));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, 0, item);
    }

    /**
     * @brief Updates the observer with new sensor data.
     * @param sensorName The name of the sensor that sent the update.
     * @param value The new numerical value of the sensor.
     * @param anomaly A boolean indicating if the new value is an anomaly.
     *
     * This method is called by a Sensor when its value changes. It updates
     * the corresponding cell in the QTableWidget, changes the cell's background
     * color based on the anomaly status, and logs anomalies to the
     * QListWidget.
     */
    void update(const std::string& sensorName, double value, bool anomaly) override {
        int row = rowMap[sensorName];
        QString valStr = QString::number(value, 'f', 2);

        QTableWidgetItem* item = new QTableWidgetItem(valStr);

        // Center the value in the cell
        item->setTextAlignment(Qt::AlignCenter);

        if (anomaly) {
            item->setBackground(Qt::red);
            item->setToolTip("Value exceeds threshold!");
            anomaliesList->addItem(
                QString("Anomaly detected: %1 = %2").arg(QString::fromStdString(sensorName)).arg(valStr)
            );
        } else {
            item->setBackground(Qt::green);
        }

        table->setItem(row, 1, item);
    }

};

#endif