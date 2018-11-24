//
// Created by Nirajan on 2018-11-23.
//

#include <chrono>
#include "City.hpp"



City::City(int id) : id(id) {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0,1000);
    x = distribution(generator);
    y = distribution(generator);
}

int City::getId() const {
    return id;
}

void City::setId(int id) {
    City::id = id;
}

int City::getX() const {
    return x;
}

void City::setX(int x) {
    City::x = x;
}

int City::getY() const {
    return y;
}

void City::setY(int y) {
    City::y = y;
}
