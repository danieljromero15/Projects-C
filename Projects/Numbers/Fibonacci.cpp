//
// Created by daniel on 2/11/24.
// Description: Enter a number and have the program generate the Fibonacci sequence to that number or to the Nth number.
//
#include <vector>
#include "iostream"

std::string printIntVector(const std::vector<unsigned long long>& vectorToPrint) {
    std::string out;
    for (unsigned long long it: vectorToPrint) {
        //out += std::to_string(i++) + " " + std::to_string(it) + "\n";
        out += std::to_string(it) + "\n";
    }
    return out;
}

std::vector<unsigned long long int> fibonacci(int max){
    std::vector<unsigned long long> fibonacciVector;

    fibonacciVector.push_back(0);
    fibonacciVector.push_back(1);

    for(int i = 2; i < max; i++){
        fibonacciVector.push_back(fibonacciVector.at(i - 2) + fibonacciVector.at(i - 1));
    }

    return fibonacciVector;
}

int main(){
    int n = 94;
    std::cout << "Max index (max 94): ";
    std::cin >> n;

    std::cout << printIntVector(fibonacci(n));

    return 0;
}