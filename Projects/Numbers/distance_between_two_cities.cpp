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

struct cityData {
    std::string country;
    double lat{}; // positive is N, negative is S
    double lng{}; // positive is E, negative is W
};

std::unordered_map<std::string, cityData> cities_map;

std::unordered_map<std::string, cityData> readWorldCities(const std::string& filePath){
    std::unordered_map<std::string, cityData> cities;

    std::fstream file(filePath);
    std::string line;

    if(file.is_open()){
        //std::cout << "file open" << "\n";
        int n=0; // 0: city 1: country 2: lat 3:long
        while(getline(file, line)){ // whole file
            std::stringstream ss(line);
            std::string lineArray[4];
            while(getline(ss, line, ',')){ // each line
                //std::cout << n << "\t" << line <<  "\n";
                lineArray[n] = line;
                n++;
                if(n > 3){
                    cityData tempData;
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
    } else{
        std::cout << "Unable to open file";
    }

    return cities;

}

void printCityData(const std::string& in){
    std::cout << in << ", ";
    std::cout << cities_map[in].country << " ";

    double lat = cities_map[in].lat;
    double lng = cities_map[in].lng;

    std::cout << std::abs(lat);
    if(lat != std::abs(lat)){ // if lat is S
        std::cout << "S";
    }else{ // lat is N
        std::cout << "N";
    }

    std::cout << " " << std::abs(lng);
    if(lng != std::abs(lng)){ // if lng is W
        std::cout << "W";
    }else{ // lng is E
        std::cout << "E";
    }
}



int main(){
    cities_map = readWorldCities("../Projects/Numbers/distance_between_two_cities_data/worldcities.csv");

    std::string input1 = "Tokyo"; // 35.6897N 139.692E
    std::string input2 = "Atlanta"; // 33.7628N 84.422W

    printCityData(input1);
    std::cout << "\n";
    printCityData(input2);

    //double distance = calculateDistance(input1, input2); // should be 11027 or 11035 km

    return 0;
}