//
// Created by Nirajan on 2018-11-23.
//

#include <algorithm>
#include <iostream>
#include "Population.hpp"

void Population::addTours(Tour t) {

    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));

    for(int i = 0; i < POPULATION_SIZE; ++i) {
        t.shuffle_cities(SHUFFLES);
        t.determine_fitness();
        population.push_back(t);
    }
}

double Population::findBestDistance() {
    double base_distance = population.at(0).getTour_distance();
    for(Tour t : population) {
        double currDist = t.getTour_distance();
        if(currDist < base_distance) {
            base_distance = currDist;
        }
    }
    return base_distance;
}

int Population::findEliteTour() {
    double base_distance = population.at(0).getTour_distance();
    int index = 0;
    for(int i = 0; i < population.size(); i++) {
        double currDist = population.at(i).getTour_distance();
        if(currDist < base_distance) {
            base_distance = currDist;
            index = i;
        }
    }
    return index;
}

void Population::selection() {
    int index = findEliteTour();
    population.at(index).printTour();
}

Tour Population::makeParentPool() {
    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(0,population.size()-1);

    Population parentPool;

    int count = 0;
    while (count < PARENT_POOL_SIZE) {
        int parentIndex = distribution(generator);
        parentPool.population.push_back(population.at(parentIndex));
        count++;
    }

    cout << "Parent Pool" << endl;
    for (auto &itr : parentPool.population) {
        cout << "POP: " << itr.getFitnessLevel() << endl;
    }

    return parentPool.population.at(parentPool.findEliteTour());

}

void Population::crossover() {

    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(0,PARENT_POOL_SIZE-1);

    int index = distribution(generator);
    int index2 = distribution(generator);

    vector<City> v;

    /*for(int i = 0; i < index;) {
        int count = 0;
        while(count < index) {
            City c = makeParentPool().getTour().at(i);
            if(std::find(v.begin(), v.end(), c) != v.end()) {
                i++;
            } else {
                v.push_back(c);
                count++;
                i++;
            }
        }
    }*/

    for(int i = 0; i < index; i++) {
        City c = makeParentPool().getTour().at(i);
        if(std::find(v.begin(), v.end(), c) != v.end()) {
            /* v contains x */
        } else {
            /* v does not contain x */
        }
        v.push_back(c);
    }

    for(int i = 0; i < abs((PARENT_POOL_SIZE-index-1)-index2); i++) {
        City c = makeParentPool().getTour().at(i);
        v.push_back(c);
    }

    for(int i = 0; i < index2; i++) {
        City c = makeParentPool().getTour().at(i);
        v.push_back(c);
    }

    cout << "The number of elements in the crossed tour are: " << v.size() << endl;
}

const vector<Tour> &Population::getPopulation() const {
    return population;
}
