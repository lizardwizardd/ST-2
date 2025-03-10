// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"

Circle::Circle() : radius(0), ference(0), area(0) {}

Circle::Circle(double radius) : Circle() {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    if (radius <= 0)
        this->radius = 0;
    else
        this->radius = radius;
    ference = 2 * M_PI * this->radius;
    area = M_PI * this->radius * radius;
}

void Circle::setFerence(double ference) {
    if (ference <= 0)
        this->ference = 0;
    else
        this->ference = ference;
    radius = this->ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::setArea(double area) {
    if (area <= 0)
        this->area = 0;
    else
        this->area = area;
    radius = sqrt(this->area / M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getFerence() {
    return ference;
}

double Circle::getArea() {
    return area;
}
