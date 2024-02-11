//
// Created by daniel on 2/11/24.
//
#include <iostream>
#include <climits>
#include "printVectors.h"

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

    std::cout << printVector<int>(intVector) << "\n";
    std::cout << printVector<double>(doubleVector, " ") << "\n";
    std::cout << printVector<std::string>(strVector, " ") << "\n";
    std::cout << printVector<unsigned long long>(ullongVector, " ") << "\n";
    std::cout << printVector<char>(charVector) << "";

    return 0;
}