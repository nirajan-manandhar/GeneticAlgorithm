#include <iostream>
#include <chrono>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"


int main() {

    City c1{1};
    City c2{2};

    cout << "X : " << c1.getX() << "Y : " << c1.getY() << endl;
    cout << "X : " << c2.getX() << "Y : " << c2.getY() << endl;


    cout << "Distance " << c1.determine_distance_between(c2) << endl;

    Tour t;
    t.addCities();
    t.printTour();
    t.shuffle_cities(64);
    t.printTour();

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