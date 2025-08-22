#ifndef QT_OBSERVER_H
#define QT_OBSERVER_H

#include "observer.h"
#include <QTableWidget>
#include <QListWidget>
#include <QString>
#include <QHeaderView>  
#include <unordered_map>

class QtObserver : public Observer {
private:
    QTableWidget* table;
    QListWidget* anomalyList;
    std::unordered_map<std::string, int> rowMap; // Map sensor name -> row index

public:
    QtObserver(QTableWidget* tableWidget, QListWidget* anomalyWidget)
        : table(tableWidget), anomalyList(anomalyWidget) {}

    void registerSensor(const std::string& name, int row) {
        rowMap[name] = row;
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(name)));
    }

    void update(const std::string& sensorName, double value, bool anomaly) override {
        int row = rowMap[sensorName];
        QString valStr = QString::number(value, 'f', 2);
        QTableWidgetItem* item = new QTableWidgetItem(valStr);
        item->setTextAlignment(Qt::AlignCenter);

        if (anomaly) {
            item->setBackground(Qt::red);
            item->setForeground(Qt::white);
            anomalyList->addItem(QString::fromStdString(sensorName + " = " + std::to_string(value)));
        } else {
            item->setBackground(Qt::green);
            item->setForeground(Qt::black);
        }

        table->setItem(row, 1, item);
    }
};

#endif
