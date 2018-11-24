//
// Created by Nirajan on 2018-11-23.
//

#include "City.hpp"

//One parameter constructor
City::City(int id) : id(id) {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution(0,1000);
    x = distribution(generator);
    y = distribution(generator);
}

int City::getId() const {
    return id;
}

void City::setId(int id) {
    City::id = id;
}

double City::getX() const {
    return x;
}

void City::setX(double x) {
    City::x = x;
}

double City::getY() const {
    return y;
}

void City::setY(double y) {
    City::y = y;
}
