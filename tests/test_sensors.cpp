#include "sensor.h"
#include <gtest/gtest.h>

TEST(SensorTest, GeneratesValueInRange) {
    Sensor temp("Temp", 0, 100);
    temp.generateValue();
    EXPECT_GE(temp.getValue(), 0);
    EXPECT_LE(temp.getValue(), 100);
}

TEST(SensorTest, DetectsAnomaly) {
    Sensor pressure("Pressure", 10, 50);
    pressure.generateValue();
    double v = pressure.getValue();

    if (v < 10 || v > 50) {
        EXPECT_TRUE(pressure.isAnomaly());
    } else {
        EXPECT_FALSE(pressure.isAnomaly());
    }
}

