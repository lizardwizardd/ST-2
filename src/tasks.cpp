// Copyright 2022 UNN-CS

#include <cstdint>
#include "circle.h"
#include "tasks.h"

double Earth() {
    double earth_rad = 6378100;

    Circle circle;
    circle.setRadius(earth_rad);

    double earth_len = circle.getFerence();
    circle.setFerence(earth_len + 1);

    return circle.getRadius() - earth_rad;
}

double track_cost() {
    Circle circle;
    circle.setRadius(3);

    double pool_square = circle.getArea();

    circle.setRadius(4);
    double s = circle.getArea() - pool_square;

    return s * 1000 + circle.getFerence() * 2000;
}
