// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"

TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5.0 * 5.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 10.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10.0 * 10.0);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    c.setFerence(20.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 20.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 20.0 / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * pow(20.0 / (2 * M_PI), 2));
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    c.setArea(50.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 50.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(50.0 / M_PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * sqrt(50.0 / M_PI));
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
}

TEST(TasksTest, RopeGap) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(gap, 0.1592, 1e-4);
}

TEST(TasksTest, PoolCost) {
    double concreteCost, fenceCost;
    calculatePoolCosts(concreteCost, fenceCost);
    EXPECT_DOUBLE_EQ(concreteCost, 1000 * (M_PI * (4 * 4 - 3 * 3)));
    EXPECT_DOUBLE_EQ(fenceCost, 2000 * (2 * M_PI * 4));
}

TEST(CircleTest, UpdateValues) {
    Circle c(5.0);
    c.setFerence(31.415926);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
    EXPECT_NEAR(c.getArea(), 78.539816, 1e-4);
    c.setArea(78.539816);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-4);
    EXPECT_NEAR(c.getFerence(), 31.415926, 1e-4);
}

TEST(CircleTest, VerySmallRadius) {
    Circle c(1e-6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e-6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e-12);
}

TEST(CircleTest, VeryLargeFerence) {
    Circle c(1.0);
    c.setFerence(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6 / (2 * M_PI));
}

TEST(CircleTest, VeryLargeArea) {
    Circle c(1.0);
    c.setArea(1e12);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(1e12 / M_PI));
}

TEST(CircleTest, UpdateMultipleTimes) {
    Circle c(3.0);
    c.setRadius(4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    c.setFerence(12.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 12.0);
    c.setArea(25.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 25.0);
}

TEST(TasksTest, DifferentPoolSizes) {
    double concreteCost, fenceCost;
    calculatePoolCosts(concreteCost, fenceCost, 5, 2);
    EXPECT_DOUBLE_EQ(concreteCost, 1000 * (M_PI * (7 * 7 - 5 * 5)));
    EXPECT_DOUBLE_EQ(fenceCost, 2000 * (2 * M_PI * 7));
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c(1.0);
    c.setFerence(-10.0);
    EXPECT_GT(c.getFerence(), 0.0);
}

TEST(CircleTest, SetNegativeArea) {
    Circle c(1.0);
    c.setArea(-50.0);
    EXPECT_GT(c.getArea(), 0.0);
}

TEST(CircleTest, TinyFerence) {
    Circle c(1.0);
    c.setFerence(1e-6);
    EXPECT_GT(c.getRadius(), 0.0);
}

TEST(CircleTest, TinyArea) {
    Circle c(1.0);
    c.setArea(1e-6);
    EXPECT_GT(c.getRadius(), 0.0);
}

TEST(CircleTest, ResetRadius) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ResetFerence) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ResetArea) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, LargeUpdateSequence) {
    Circle c(1.0);
    for (int i = 1; i <= 100; ++i) {
        c.setRadius(i);
    }
    EXPECT_DOUBLE_EQ(c.getRadius(), 100.0);
}

TEST(CircleTest, VerifyPiDependence) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence() / c.getRadius(), 2 * M_PI, 1e-6);
}

TEST(CircleTest, SmallChanges) {
    Circle c(1.0);
    c.setRadius(1.0001);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1.0001, 1e-6);
}
