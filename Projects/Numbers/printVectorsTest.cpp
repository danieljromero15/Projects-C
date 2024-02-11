//
// Created by daniel on 2/11/24.
//
#include <iostream>
#include <climits>
#include "printCollections.h"
#include "tuple"

int main(){
    std::vector<std::string> strVector;
    strVector.emplace_back("Hi");
    strVector.emplace_back("Hello");
    strVector.emplace_back("Bob");

    std::vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);

    std::vector<double> doubleVector;
    doubleVector.push_back(1.25);
    doubleVector.push_back(3.5);

    std::vector<unsigned long long> ullongVector;
    ullongVector.push_back(ULLONG_MAX);
    ullongVector.push_back(2);

    std::vector<char> charVector;
    charVector.push_back('c');
    charVector.push_back('h');

    std::cout << printVector<>(intVector) << "\n";
    std::cout << printVector<>(doubleVector, " ") << "\n";
    std::cout << printVector<>(strVector, " ") << "\n";
    std::cout << printVector<>(ullongVector, " ") << "\n";
    std::cout << printVector<>(charVector) << "" << "\n";

    std::tuple<int, int> testTuple = std::make_tuple(1, 2);

    std::cout << "Tuple Size: " << std::tuple_size<decltype(testTuple)>::value << "\n";
    std::cout << printTuple(testTuple, "\t") << "\n";

    return 0;
}