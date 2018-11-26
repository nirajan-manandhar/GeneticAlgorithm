//
// Created by Nirajan on 2018-11-23.
//

#include <iostream>
#include "Tour.hpp"


void Tour::addCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++) {
        City c(i);
        tour.push_back(c);
    }
}

void Tour::determine_fitness() {
    vector<City>::iterator itr;
    City firstCity;
    City prevCity;
    double totalDistance = 0;
    for(itr = tour.begin(); itr != tour.end(); ++itr) {
        if(itr == tour.begin()){
            firstCity = *itr;
            prevCity = *itr;
        } else {
            totalDistance += itr->determine_distance_between(prevCity);
            prevCity = *itr;

            //Connects the last city with the first one, making a round trip
            if (itr == tour.end()) {
                totalDistance += itr->determine_distance_between(firstCity);
            }
        }
    }
    tour_distance = totalDistance;
    fitnessLevel = ((1.0/totalDistance) * SCALAR);
}

void Tour::shuffle_cities(int numOfShuffles) {
    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(0,tour.size()-1);
    int count = 0;
    while (count < numOfShuffles) {
        int first = distribution(generator);
        int second = distribution(generator);

        if (first != second) {
            swap(tour.at(first), tour.at(second));
            count++;
        }
    }
}

void Tour::printTour() {
    for (auto &itr : tour) {
        cout << "ID: " << itr.getId() << " X : " << itr.getX() << " Y : " << itr.getY() << endl;
    }
}

double Tour::getFitnessLevel() const {
    return fitnessLevel;
}

const vector<City> &Tour::getTour() const {
    return tour;
}

double Tour::getTour_distance() const {
    return tour_distance;
}

void swap(Tour &first, Tour &second) {
    using std::swap;
    swap(first.fitnessLevel, second.fitnessLevel);
    swap(first.tour_distance, second.tour_distance);
    swap(first.tour, second.tour);
}