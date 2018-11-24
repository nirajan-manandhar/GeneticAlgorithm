//
// Created by Nirajan on 2018-11-23.
//

#include <algorithm>
#include "Population.hpp"

void Population::addTours(Tour t) {

    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));

    for(int i = 0; i < POPULATION_SIZE; ++i) {
        /*shuffle(t.getTour().begin(),t.getTour().end(), generator);
        population.push_back(t);*/
    }
}

void Population::findElite() {
    Tour eliteTour;
    for(Tour t : population) {
        t.getFitnessLevel();
        if(t.getFitnessLevel() > eliteTour.getFitnessLevel()) {

        }
    }
}
