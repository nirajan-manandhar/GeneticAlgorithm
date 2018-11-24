//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <random>
#include <chrono>

using namespace std;

class City {
private:
    //ID/Name of the city
    int id;

    //Latitude value
    double x;

    //Longitude
    double y;

public:
    //Default constructor
    City() = default;

    explicit City(int id);

    int getId() const;

    void setId(int id);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

};


#endif //GENETICALGORITHM_CITY_HPP
