//
// Created by daniel on 2/11/24.
// Description: Calculates the distance between two cities and allows the user to specify a unit of distance.
//              This program may require finding coordinates for the cities like latitude and longitude.
//

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::pair;
using std::map;

struct city_info {
    string country;
    double lat{}; // positive is N, negative is S
    double lng{}; // positive is E, negative is W
};

map<pair<string, int>, city_info> cities_data_map;

void printCityData(const pair<string, int> &cityKey) {
    //cout << cityKey.first << cityKey.second << ", ";
    cout << cityKey.first << ", ";

    city_info cityInfo = cities_data_map[cityKey];

    string country = cityInfo.country;
    double lat = cityInfo.lat;
    double lng = cityInfo.lng;

    cout << country << " ";

    cout << std::abs(lat);
    if (lat != std::abs(lat)) { // if lat is S
        cout << "S";
    } else { // lat is N
        cout << "N";
    }

    cout << " " << std::abs(lng);
    if (lng != std::abs(lng)) { // if lng is W
        cout << "W";
    } else { // lng is E
        cout << "E";
    }
}

void assignValues(const string &cityName, int n, map<pair<string, int>, city_info> &mapToWriteTo,
                  const city_info &tempData) {
    if (mapToWriteTo.count(std::make_pair(cityName, n))) {
        assignValues(cityName, n + 1, mapToWriteTo, tempData);
        //printCityData(lineArray[0], 1);
    } else {
        mapToWriteTo[std::make_pair(cityName, n)] = tempData;
        //printCityData(lineArray[0], 0);
    }
}

std::vector<std::tuple<string, string, double, double>>
returnDuplicates(const string &cityName, map<pair<string, int>, city_info> mapToRead) {
    int n = 0;
    std::vector<std::tuple<string, string, double, double>> duplicates;
    std::tuple<string, string, double, double> cityTuple;

    while (mapToRead.count(std::make_pair(cityName, n))) {
        city_info info = mapToRead[std::make_pair(cityName, n)];
        cityTuple = std::make_tuple(cityName, info.country, info.lat, info.lng);
        duplicates.push_back(cityTuple);
        n++;
    }

    return duplicates;
}

map<pair<string, int>, city_info> readWorldCities(const string &filePath) {
    map<pair<string, int>, city_info> cities;

    std::fstream file(filePath);
    string line;

    if (file.is_open()) {
        //cout << "file open" << "\n";
        int n = 0; // 0: city 1: country 2: lat 3:long
        while (getline(file, line)) { // whole file
            std::stringstream ss(line);
            string lineArray[4];
            while (getline(ss, line, ',')) { // each line
                //cout << n << "\t" << line <<  "\n";
                lineArray[n] = line;
                n++;
                if (n > 3) {
                    city_info tempData;
                    tempData.country = lineArray[1];
                    tempData.lat = std::stod(lineArray[2]);
                    tempData.lng = std::stod(lineArray[3]);

                    //pair cityKey = std::make_pair(lineArray[0], 0);
                    assignValues(lineArray[0], 0, cities, tempData);


                    n = 0; // resets counter
                }
            }
            //cities.insert(lineArray[0], lineArray[1], lineArray[2], lineArray[3]);
        }
        file.close();
    } else {
        cout
                << "Unable to open data file.\nPlease put worldcities.csv in the same folder as the executable or specify the path of the file as a command line argument";
        exit(0);
    }

    return cities;

}

pair<string, int> checkForDuplicates(const string &cityName) {
    std::vector<std::tuple<string, string, double, double>> duplicates = returnDuplicates(cityName, cities_data_map);
    int selection = 0;
    if (duplicates.size() == 1) {
        return std::make_pair(cityName, selection);
    } else {
        cout << "Duplicates found.\n";
        for (int i = 0; i < duplicates.size(); i++) {
            cout << "\t" << i + 1 << ": ";
            printCityData(std::make_pair(cityName, i));
            cout << "\n";
        }
        while (true) {
            cout << "Please make a selection: ";
            cin >> selection;
            if (cin.fail()) {
                cin.clear();
                cin.sync();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            } else if (selection > 0 && selection <= duplicates.size()) {
                selection--;

                return std::make_pair(cityName, selection);
            }
            cout << "Please type a number between 1 and " << duplicates.size();
        }
    }
}

double toRadians(double in) {
    return in * (M_PI / 180);
}

double calculateDistance(const pair<string, int> &city1, const pair<string, int> &city2) {
    double lat1 = toRadians(cities_data_map[city1].lat);
    double lon1 = toRadians(cities_data_map[city1].lng);
    double lat2 = toRadians(cities_data_map[city2].lat);
    double lon2 = toRadians(cities_data_map[city2].lng);

    double result = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));

    return result * 6371;
}

int main(int argc, char *argv[]) {
    //cities_data_map = readWorldCities("../Projects/Numbers/distance_between_two_cities_data/worldcities.csv");
    string filePath = "worldcities.csv";
    if (argc >= 2) {
        filePath = "";
        for (int i = 1; i < argc; i++) {
            filePath += argv[i];
        }
    }
    cities_data_map = readWorldCities(filePath);

    pair<string, int> city1, city2;
    string input1;// = "New York";
    string input2 = "\u200B";// = "San Francisco";
    bool valid_city1 = false;
    bool valid_city2 = false;

    cout << "\nPlease enter two cities to calculate the distance between:\n";
    while (!valid_city1 || !valid_city2) {
        if (!valid_city1) {
            cout << "City 1: ";
            std::getline(cin, input1);
            cin.clear();
            cin.sync();
            if (!cities_data_map.count(std::make_pair(input1, 0))) {
                cout << "Please enter a valid city!\n";
                continue;
            } else {
                valid_city1 = true;
                city1 = checkForDuplicates(input1);
            }
        }

        cin.clear();
        cin.sync();

        if (input2 != "\u200B") {
            cout << "City 2: ";
        }
        std::getline(cin, input2);
        cin.clear();
        cin.sync();
        if (!cities_data_map.count(std::make_pair(input2, 0))) {
            if (input2 != "") { cout << "Please enter a valid city!\n"; }
            continue;
        } else {
            valid_city2 = true;
            city2 = checkForDuplicates(input2);
        }
    }

    cout << "\n";
    printCityData(city1);
    cout << "\n";
    printCityData(city2);
    cout << "\n";

    cout << "\nDistance between " << city1.first << " and " << city2.first << ": ";

    double distance1 = calculateDistance(city1, city2);

    cout << distance1 << "km\n";

    return 0;
}