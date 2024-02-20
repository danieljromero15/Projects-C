//
// Created by daniel on 2/18/24.
//

#include <vector>
#include <iostream>
#include "../.headers/printCollections.h"
#include <algorithm>

int main(int argc, char *argv[]) {
    int numbers_size = 100;
    if (argc >= 2) {
        // cmdline arguments var definition go here
        //std::cout << std::stoi(argv[1]) + 1 << std::endl;
        numbers_size = std::stoi(argv[1]);
    }
    std::vector<int> primes;
    std::vector<int> numbers;
    primes.push_back(2);

    for (int i = 2; i <= numbers_size; i++) {
        numbers.push_back(i);
    }

    //std::cout << "numbers: " << printVector<int>(numbers, " ") << std::endl << std::endl;

    for (int i = 0; i < numbers_size; i++) {
        for (int j = 0; j <= numbers.size(); j++) {
            if (numbers[j] % primes[i] == 0) {
                //std::cout << numbers[j] << "\t";
                numbers.erase(numbers.begin() + j);
                //std::cout << printVector<int>(numbers, " ") << std::endl;
            }
            //if(numbers[j] == numbers_size){break;}
        }
        //std::cout << numbers[0] << " ";
        if (std::find(primes.begin(), primes.end(), numbers[0]) != primes.end()) {
            break;
        } else {
            primes.push_back(numbers[0]);
        }
    }
    //std::cout << std::endl;

    //std::cout << std::endl << "numbers: " << printVector<int>(numbers, " ") << std::endl;
    std::cout << "Primes up to " << numbers_size << ": " << printVector<int>(primes, " ") << std::endl;

    return 0;
}