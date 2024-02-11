//
// Created by daniel on 2/11/24.
// Description: Enter a number and have the program generate the Fibonacci sequence to that number or to the Nth number.
//
#include <vector>
#include "iostream"
#include "printVectors.h"

std::vector<unsigned long long> fibonacci(int max){
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

    std::vector<unsigned long long> fibonacciVector = fibonacci(n);
    std::cout << printVector<unsigned long long>(fibonacciVector, "\n");

    return 0;
}