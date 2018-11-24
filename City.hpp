//
// Created by Nirajan on 2018-11-23.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <random>

using namespace std;

class City {
private:
    //ID/Name of the city
    int id;

    //Latitude value
    int x;

    //Longitude
    int y;
public:
    //Constructor
    City(int id);

    //Getter for the city ID/Name.
    int getId() const;

    //Setter for the city ID/Name.
    void setId(int id);

    //Getter for Latitude
    int getX() const;

    //Setter for the Latitude
    void setX(int x);

    //Getter for the Longitude
    int getY() const;

    //Setter for the Longitude
    void setY(int y);

    //


};


#endif //GENETICALGORITHM_CITY_HPP
