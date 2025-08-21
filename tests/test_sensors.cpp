#include "sensor.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

// --- Parametrized test fixture ---
class ParamSensorTest : public ::testing::TestWithParam<std::tuple<std::string, double, double>> {};

TEST_P(ParamSensorTest, GeneratesValueWithinRange) {
    auto [name, minLimit, maxLimit] = GetParam();
    Sensor s(name, minLimit, maxLimit);

    // Test multiple generated values
    for (int i = 0; i < 100; ++i) {
        s.generateValue();
        double val = s.getValue();
        EXPECT_GE(val, minLimit) << name << " generated value below minimum!";
        EXPECT_LE(val, maxLimit * 1.5) << name << " generated value above allowed maximum!";
    }
}

TEST_P(ParamSensorTest, DetectsAnomalyCorrectly) {
    auto [name, minLimit, maxLimit] = GetParam();
    Sensor s(name, minLimit, maxLimit);

    // Value inside range → should not be anomaly
    s.setValue((minLimit + maxLimit) / 2);
    EXPECT_FALSE(s.isAnomaly()) << name << " incorrectly reports anomaly for valid value!";

    // Value below minimum → should be anomaly
    s.setValue(minLimit - 1);
    EXPECT_TRUE(s.isAnomaly()) << name << " failed to detect anomaly below minimum!";

    // Value above maximum → should be anomaly
    s.setValue(maxLimit + 1);
    EXPECT_TRUE(s.isAnomaly()) << name << " failed to detect anomaly above maximum!";
}

// --- Instantiate the suite with multiple sensors ---
INSTANTIATE_TEST_SUITE_P(
    AllSensors,
    ParamSensorTest,
    ::testing::Values(
        std::make_tuple("Temperature", 0.0, 100.0),
        std::make_tuple("Pressure", 10.0, 50.0),
        std::make_tuple("Radar", 100.0, 1000.0),
        std::make_tuple("Humidity", 20.0, 80.0)
    )
);
