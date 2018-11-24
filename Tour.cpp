//
// Created by Nirajan on 2018-11-23.
//

#include "Tour.hpp"


void Tour::addCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++) {
        City c(i);
        tour.push_back(c);
    }
}

void Tour::calculateFitness() {
    vector<City>::iterator itr;
    double totalDistance = 0;
    double prevX = 0;
    double prevY = 0;
    for(itr = tour.begin(); itr != tour.end(); ++itr) {
        if(itr == tour.begin()){
            prevX = itr->getX();
            prevY = itr->getY();
        } else {
            double xDist = abs(prevX - itr->getX());
            double yDist = abs(prevY - itr->getY());
            double xSquared = (xDist * xDist);
            double ySquared = (yDist * yDist);
            double netDist = sqrt((xSquared + ySquared));
            totalDistance += netDist;
        }
    }
    fitnessLevel = ((1.0/totalDistance) * SCALAR);
}
