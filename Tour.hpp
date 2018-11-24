//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "City.hpp"

class Tour {

private:
    vector<City> tour;
    double fitnessLevel;
public:
    //Number of cities in a tour
    const int CITIES_IN_TOUR = 32;

    //This a number that is used to make the fitness level
    const int SCALAR = 1000000;

    //Default Constructor
    Tour() = default;

    //Add cities to tour
    void addCities();

    //Tour fitness calculator
    void calculateFitness();

};


#endif //GENETICALGORITHM_TOUR_HPP
