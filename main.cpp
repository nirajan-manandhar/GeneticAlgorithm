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

    cout << "best distance: " << p.findBestDistance() << endl;
    p.selection();
    cout << "best fitness = " << 1.0/p.findBestDistance() * 10000000 << endl;

    for (auto &itr : p.getPopulation()) {
        cout << "Fitness: " << itr.getFitnessLevel() << endl;
    }

    p.makeParentPool();

    //p.crossover();

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