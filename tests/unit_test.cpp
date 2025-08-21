#include "sensor.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class ParamSensorTest : public ::testing::TestWithParam<std::tuple<std::string, double, double>> {};

TEST_P(ParamSensorTest, DetectsAnomalyCorrectly) {
    auto [name, minLimit, maxLimit] = GetParam();
    Sensor s(name, minLimit, maxLimit);

    s.setValue((minLimit + maxLimit)/2);
    EXPECT_FALSE(s.isAnomaly());

    s.setValue(minLimit - 1);
    EXPECT_TRUE(s.isAnomaly());

    s.setValue(maxLimit + 1);
    EXPECT_TRUE(s.isAnomaly());
}

INSTANTIATE_TEST_SUITE_P(
    AllSensors,
    ParamSensorTest,
    ::testing::Values(
        std::make_tuple("Temperature", 0.0, 100.0),
        std::make_tuple("Pressure", 10.0, 50.0),
        std::make_tuple("Speed", 0.0, 40.0)
    )
);
