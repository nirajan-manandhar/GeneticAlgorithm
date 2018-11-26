#include <iostream>
#include <chrono>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"


int main() {

    Tour t;
    t.addCities();
    Population p;
    p.addTours(t);

    for (auto &itr : p.getPopulation()) {
        cout << "Fitness: " << itr.getFitnessLevel() << endl;
    }

    //p.makeParentPool();

    p.createChildTour();

    //Create a tour with cities
    /*Tour worldTour{};
    worldTour.addCities();
    worldTour.calculateFitness();
    cout << worldTour.getFitnessLevel() << endl;*/

    //Create a population with different routes through those cities
//    Population pop{};
//    pop.addTours(worldTour);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}