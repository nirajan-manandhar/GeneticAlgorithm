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

    //Mutation Rate
    const int MUTATION_RATE = 85;

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

    //Create a child tour by crossing parents
    Tour createChildTour();

    void crossOver();

    void mutate();



    double findBestDistance();

    const vector<Tour> &getPopulation() const;

};


#endif //GENETICALGORITHM_POPULATION_HPP
