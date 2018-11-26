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

    //Number of shuffles
    const int SHUFFLES = 64;

    //Number of parent in parent pool
    const int PARENT_POOL_SIZE = 12;

    //Number of parent to be crossed
    const int NUMBER_OF_PARENTS = 1;

public:

    //Default Constructor
    Population() = default;

    //Populate a Population with tours
    void addTours(Tour t);

    //Find the best tour in the population and puts it
    //at the beginning of the population.
    int findEliteTour();

    //keep the best tour by moving the fittest to the front of the population. We won’t
    //change it in this iteration, and we will call it an ’elite’ individual
    void selection();

    //Create a subset of tours
    Tour makeParentPool();

    void crossover();

    double findBestDistance();

    const vector<Tour> &getPopulation() const;

};


#endif //GENETICALGORITHM_POPULATION_HPP
