//
// Created by daniel on 2/11/24.
// Description: Have the user enter a number and find all Prime Factors (if there are any) and display them.
//

#include <vector>
#include <iostream>
#include "../.headers/printCollections.h"

bool isPrime(int n);

std::tuple<int, int> getFactors(int n) {
    std::tuple<int, int> factors = std::make_tuple(1, n);
    if (!isPrime(n)) {
        for (int i = 2; i < n - 1; i++) {
            if (n % i == 0) {
                if (std::get<0>(factors) == 1) {
                    std::get<0>(factors) = i;
                }
                std::get<1>(factors) = i;
            }
        }
    } else {
        std::cout << n << " is prime";
        std::get<1>(factors) = 0; // if factors[1] is 0, number is prime
    }
    //std::cout << printTuple(factors, " ") << "\n";
    return factors;
}

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            //std::cout << n << "%" << i << "=" << n % i << " " << n << "\n";
            return false;
        }
    }
    return true;
}

int multiplyIntVector(const std::vector<int> &vectorToMultiply) {
    int product = 1;
    for (int i: vectorToMultiply) {
        product *= i;
    }
    return product;
}

void printPrimeFactors(int n) {
    if (n == 0) {
        std::cout << "Anything multiplied by 0 is 0.";
        return;
    }
    if (n == 1) {
        std::cout << "1 can only be multiplied by itself.";
        return;
    }

    std::vector<int> prime_factors;
    std::tuple<int, int> factors = getFactors(n);
    if (std::get<1>(factors) > 0) {
        prime_factors.push_back(std::get<0>(factors));
        while (!isPrime(std::get<1>(factors))) {
            factors = getFactors(std::get<1>(factors));
            prime_factors.push_back(std::get<0>(factors));
        }
        prime_factors.push_back(std::get<1>(factors));
        std::cout << printVector(prime_factors, " x ") << "\b\b" << "= " << multiplyIntVector(prime_factors);
    }
}

int main() {
    int n = 100;
    std::cout << "Enter number to find prime factors: ";
    std::cin >> n;

    printPrimeFactors(n);

    return 0;
}