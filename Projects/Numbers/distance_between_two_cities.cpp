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
    double lat;
    double lng;
};

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
                    for(int i = 0; i < 4; i++){
                        std::cout << lineArray[i] << " ";
                    }
                    std::cout << "\n";
                    n = 0;
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

int main(){
    readWorldCities("../Projects/Numbers/worldcities_data/worldcities.csv");

    return 0;
}