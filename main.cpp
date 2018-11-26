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
    cout << "selection" << endl;



    p.selection();
    cout << "evaluate" << endl;

    double base_dist = p.getPopulation().at(0).getTour_distance();
    double best_dist = p.getPopulation().at(0).getTour_distance();

    cout << "Base Distance" << base_dist << endl;
    cout << "Best Distance" << best_dist << endl;


    while((best_dist/base_dist) > 0.30){
        best_dist = p.findBestDistance();
        p.crossOver();
        p.mutate();
        p.evaluate();
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}