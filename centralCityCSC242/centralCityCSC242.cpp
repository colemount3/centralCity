// centralCityCSC242.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <cmath>


struct City {
    double x;
    double y;
};

// Calculate the distance between two cities using the distance formula
double distance(City c1, City c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

int main() {
    int numCities;
    std::vector<City> cities; // initialize vector
    std::cout << "Enter the number of cities: ";
    std::cin >> numCities;
    std::cout << "Enter the coordinates of the cities: ";
    // add coordinates of each city to vector
    for (int i = 0; i < numCities; i++) {
        City city;
        std::cin >> city.x >> city.y;
        cities.push_back(city); //pushback adds to vector
    }
    int centralCity = 0; 
    double minTotalDistance = 1e9; //city with lowest total distance is central
    // Loop through each city to find the central city with the minimum total distance
    //double for loop will calc distance from first city to all cities, then second city to all cities and so on
    for (int i = 0; i < numCities; i++) {
        double totalDistance = 0;
        for (int j = 0; j < numCities; j++) {
            if (i != j) { //prevents calc distance to itself
                totalDistance += distance(cities[i], cities[j]); //function distance calculates distance to each city, then adds it to total distance
            }
        }
        if (totalDistance < minTotalDistance) { // Check if this city has a shorter total distance than the current minimum
            minTotalDistance = totalDistance; 
            centralCity = i; //if total distance is less than minTotalDistance, new central city is i
        }
    }
    // Printresults
    std::cout << "The central city is at (" << cities[centralCity].x << ", " << cities[centralCity].y << ")" << std::endl;
    std::cout << "The total distance to all other cities is " << minTotalDistance << std::endl; 
  
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
