//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:

    vector<Tour> population;

    //Number of tours in a population
    const int POPULATION_SIZE = 32;

    const int SHUFFLES = 64;

public:

    //Default Constructor
    Population() = default;

    //Populate a Population with tours
    void addTours(Tour t);

    void findElite();


};


#endif //GENETICALGORITHM_POPULATION_HPP
