#ifndef QT_OBSERVER_H
#define QT_OBSERVER_H

#include "observer.h"
#include <QTableWidget>
#include <QString>
#include <unordered_map>

class QtObserver : public Observer {
private:
    QTableWidget* table;
    std::unordered_map<std::string, int> rowMap; // Map sensor name -> row index
public:
    QtObserver(QTableWidget* tableWidget) : table(tableWidget) {}

    void registerSensor(const std::string& name, int row) {
        rowMap[name] = row;
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(name)));
    }

    void update(const std::string& sensorName, double value, bool anomaly) override {
        int row = rowMap[sensorName];
        QString valStr = QString::number(value, 'f', 2);
        if (anomaly) valStr += " ⚠";
        table->setItem(row, 1, new QTableWidgetItem(valStr));
    }
};

#endif
