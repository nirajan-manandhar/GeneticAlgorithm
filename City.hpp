//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

class City {
private:
    //ID/Name of the city
    int id;

    //Latitude value
    double x;

    //Longitude
    double y;

    //The map's min value
    const int MAP_MIN = 0;

    //The map's max value
    const int MAP_MAX = 1000;

public:

    //Default constructor
    City() = default;

    //Constructor that only takes id.
    explicit City(int id);

    //Three parameter constructor
    City(int id, double x, double y);

    //Gets the distance between two cities
    double determine_distance_between(City c);

    //Copy Constructor
    City(const City& c);

    //Swap
    friend void swap(City &first, City &second);

    //Destructor
    ~City() = default;

    //Overloaded assignment operator
    City&operator=(City other);

    //Overloaded equality operator
    bool operator==(const City& other);

    //Getter for ID
    int getId() const;

    //Getter for latitude
    double getX() const;

    //Getter for longitude
    double getY() const;
};


#endif //GENETICALGORITHM_CITY_HPP
