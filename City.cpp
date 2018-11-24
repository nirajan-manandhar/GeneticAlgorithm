//
// Created by Nirajan on 2018-11-23.
//

#include "City.hpp"
#include <algorithm>


//One parameter constructor
City::City(int id) : id(id) {
    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_real_distribution<double> distribution(MAP_MIN,MAP_MAX);
    x = distribution(generator);
    y = distribution(generator);
}

//Three parameter constructor
City::City(int id, double x, double y) : id(id), x(x), y(y) {}

//Copy constructor
City::City(const City &c) : id(c.id), x(c.x), y(c.y) {}

//Swap
void swap(City &first, City &second) {
    using std::swap;
    swap(first.id, second.id);
    swap(first.x, second.x);
    swap(first.y, second.y);
}

//Assignment Operator
City &City::operator=(City other) {
    swap(*this, other);
    return *this;
}

double City::determine_distance_between(City c) {
    double xDist = abs(this->x - c.x);
    double yDist = abs(this->y - c.y);
    double xSquared = (xDist * xDist);
    double ySquared = (yDist * yDist);
    double netDist = sqrt((xSquared + ySquared));
    return netDist;
}

double City::getX() const {
    return x;
}

double City::getY() const {
    return y;
}

int City::getId() const {
    return id;
}




