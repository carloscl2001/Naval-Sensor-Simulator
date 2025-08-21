#include "sensor_system.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

// Fixture parametrizado para integración
class ParamSensorSystemTest : public ::testing::TestWithParam<std::vector<std::tuple<std::string,double,double>>> {};

TEST_P(ParamSensorSystemTest, DetectsSystemAnomalies) {
    auto sensorParams = GetParam();
    SensorSystem system;

    std::vector<Sensor> sensors;
    for (auto &[name, min, max] : sensorParams) {
        Sensor s(name, min, max);
        s.generateValue();       // generamos un valor aleatorio
        system.addSensor(s);
        sensors.push_back(s);
    }

    // Inyectamos anomalía en el primer sensor
    sensors[0].setValue(std::get<2>(sensorParams[0]) * 2); // valor fuera de rango

    // Verificamos que al menos un sensor detecte anomalía
    bool anyAnomaly = false;
    for (auto &s : sensors)
        if (s.isAnomaly()) anyAnomaly = true;

    EXPECT_TRUE(anyAnomaly);
}

// Instanciamos distintos conjuntos de sensores
INSTANTIATE_TEST_SUITE_P(
    MultipleSensorConfigs,
    ParamSensorSystemTest,
    ::testing::Values(
        std::vector<std::tuple<std::string,double,double>>{
            {"Temperature", 0.0, 100.0}, {"Pressure", 10.0, 50.0}
        },
        std::vector<std::tuple<std::string,double,double>>{
            {"Speed", 0.0, 40.0}, {"Humidity", 20.0, 80.0}
        },
        std::vector<std::tuple<std::string,double,double>>{
            {"Temperature", 0.0, 100.0}, {"Speed", 0.0, 40.0}, {"Pressure", 10.0, 50.0}
        }
    )
);
