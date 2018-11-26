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

Tour Population::createChildTour() {
    Tour parent1 = makeParentPool();
    Tour parent2 = makeParentPool();

    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(0,32);
    int index = distribution(generator);

    vector<City> crossedTour;

    int count = 0;

    for(int i = 0; i < index; i++) {
        City c = parent1.getTour().at(i);
        crossedTour.push_back(c);
        count++;
    }

    int i = 0;
    while( count < 32) {
        City c = parent2.getTour().at(i);
        if(std::find(crossedTour.begin(), crossedTour.end(), c) != crossedTour.end()) {
            i++;
        } else {
            crossedTour.push_back(c);
            count++;
            i++;
        }
    }

    Tour tour(crossedTour);

    return tour;
}

void Population::crossOver() {
    for(int i = 0; i < population.size(); i++) {
        if((i%2!=0) && i != 0) {
            population.at(i) = createChildTour();
        }
    }
}

//Randomly mutate up a few tours (excluding the elite tour!). Calculate a random
//mutation value for each city in a specified specified tour. If this value < MUTATION_RATE, then
//the city is swapped with a randomly chosen adjacent city from the same tour.
void Population::mutate() {
    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(0, 100);
    uniform_int_distribution<int> distribution2(1, POPULATION_SIZE);

    for(int i = 1; i < 5; i++) {
        int tourIndex = distribution2(generator);

        population.at(tourIndex).getTour();

        for(int j = 0; j < 32; j++) {
            int mutationVal = distribution(generator);
            if(mutationVal < MUTATION_RATE) {
                population.at(tourIndex).mutate(j);
            }

        }

    }
}

const vector<Tour> &Population::getPopulation() const {
    return population;
}
