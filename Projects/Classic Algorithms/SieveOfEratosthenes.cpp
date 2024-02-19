//
// Created by daniel on 2/18/24.
//

#include <vector>
#include <iostream>
#include "printCollections.h"

int main() {
    std::vector<int> primes;
    std::vector<int> numbers;
    int numbers_size = 100;
    primes.push_back(1);

    for(int i = 1; i <= numbers_size; i++){
        numbers.push_back(i);
    }

    std::cout << printVector<int>(numbers, " ") << std::endl << std::endl;

    //for(int i = 0; i < numbers_size; i++){
    for(int j = 0; j <= numbers.size(); j++){
        if(numbers[j] % primes[0] == 0){
            std::cout << numbers[j] << "\t";
            numbers.erase(numbers.begin() + j);
            std::cout << printVector<int>(numbers, " ") << std::endl;
        }
        //if(numbers[j] == numbers_size){break;}
    }
    primes.push_back(numbers[0]);
    std::cout << std::endl;//}

    primes.erase(primes.begin()); // removes 1


    std::cout << std::endl << printVector<int>(numbers, " ") << std::endl;
    std::cout << printVector<int>(primes, " ") << std::endl;

    return 0;
}