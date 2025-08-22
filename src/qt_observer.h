#ifndef QT_OBSERVER_H
#define QT_OBSERVER_H

#include "observer.h"
#include <QTableWidget>
#include <QListWidget>
#include <QString>
#include <QColor>
#include <unordered_map>

class QtObserver : public Observer {
private:
    QTableWidget* table;
    QListWidget* anomaliesList;
    std::unordered_map<std::string, int> rowMap; // Map sensor name -> row index
public:
    QtObserver(QTableWidget* tableWidget, QListWidget* anomaliesWidget)
        : table(tableWidget), anomaliesList(anomaliesWidget) {}

    void registerSensor(const std::string& name, int row) {
        rowMap[name] = row;
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(name)));
    }

    void update(const std::string& sensorName, double value, bool anomaly) override {
        int row = rowMap[sensorName];
        QString valStr = QString::number(value, 'f', 2);

        QTableWidgetItem* item = new QTableWidgetItem(valStr);

        // Centrar el valor en la celda
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
