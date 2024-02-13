//
// Created by daniel on 2/11/24.
// Description: Calculates the distance between two cities and allows the user to specify a unit of distance.
//              This program may require finding coordinates for the cities like latitude and longitude.
//

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

struct city_info {
    std::string country;
    double lat{}; // positive is N, negative is S
    double lng{}; // positive is E, negative is W
};

std::unordered_map<std::string, city_info> cities_data_map;

std::unordered_map<std::string, city_info> readWorldCities(const std::string &filePath) {
    std::unordered_map<std::string, city_info> cities;

    std::fstream file(filePath);
    std::string line;

    if (file.is_open()) {
        //std::cout << "file open" << "\n";
        int n = 0; // 0: city 1: country 2: lat 3:long
        while (getline(file, line)) { // whole file
            std::stringstream ss(line);
            std::string lineArray[4];
            while (getline(ss, line, ',')) { // each line
                //std::cout << n << "\t" << line <<  "\n";
                lineArray[n] = line;
                n++;
                if (n > 3) {
                    city_info tempData;
                    tempData.country = lineArray[1];
                    tempData.lat = std::stod(lineArray[2]);
                    tempData.lng = std::stod(lineArray[3]);
                    cities[lineArray[0]] = tempData;

                    n = 0; // resets counter
                }
            }
            //cities.insert(lineArray[0], lineArray[1], lineArray[2], lineArray[3]);
        }
        file.close();
    } else {
        std::cout << "Unable to open data file";
        exit(0);
    }

    return cities;

}

void printCityData(const std::string &in) {
    std::cout << in << ", ";
    std::cout << cities_data_map[in].country << " ";

    double lat = cities_data_map[in].lat;
    double lng = cities_data_map[in].lng;

    std::cout << std::abs(lat);
    if (lat != std::abs(lat)) { // if lat is S
        std::cout << "S";
    } else { // lat is N
        std::cout << "N";
    }

    std::cout << " " << std::abs(lng);
    if (lng != std::abs(lng)) { // if lng is W
        std::cout << "W";
    } else { // lng is E
        std::cout << "E";
    }
}

double toRadians(double in) {
    return in * (M_PI / 180);
}

double calculateDistance1(const std::string &city1, const std::string &city2) {
    double lat1 = toRadians(cities_data_map[city1].lat);
    double lon1 = toRadians(cities_data_map[city1].lng);
    double lat2 = toRadians(cities_data_map[city2].lat);
    double lon2 = toRadians(cities_data_map[city2].lng);

    double result = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));

    return result * 6371;
}

int main() {
    cities_data_map = readWorldCities("../Projects/Numbers/distance_between_two_cities_data/worldcities.csv");
    std::string input1;
    std::string input2;
    bool valid_city1 = false;
    bool valid_city2 = false;

    std::cout << "\nPlease enter two cities to calculate the distance between:\n";
    while (!valid_city1 || !valid_city2) {
        if (!valid_city1) {
            std::cout << "City 1: ";
            std::getline(std::cin, input1);
            if (cities_data_map.find(input1) == cities_data_map.end()) {
                std::cout << "Please enter a valid city!\n";
                continue;
            } else {
                valid_city1 = true;
            }
        }

        std::cout << "City 2: ";
        std::getline(std::cin, input2);
        if (cities_data_map.find(input2) == cities_data_map.end()) {
            std::cout << "Please enter a valid city!\n";
        } else {
            valid_city2 = true;
        }
    }

    std::cout << "\n";
    printCityData(input1);
    std::cout << "\n";
    printCityData(input2);

    std::cout << "\nDistance between " << input1 << " and " << input2 << ": ";

    double distance1 = calculateDistance1(input1, input2);

    std::cout << distance1 << "km\n";

    return 0;
}