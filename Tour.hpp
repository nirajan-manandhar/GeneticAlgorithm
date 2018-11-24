//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "City.hpp"

class Tour {

private:
    vector<City> tour;
    double fitnessLevel = 0;
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
    void determine_fitness();

    //Shuffles the order of the cities in a tour
    void shuffle_cities(int numOfShuffles);

    //Prints out cities in tour, in order
    void printTour();

    //Getter for city list
    const vector<City> &getTour() const;

    //Getter for fitnessLevel
    double getFitnessLevel() const;

};


#endif //GENETICALGORITHM_TOUR_HPP
