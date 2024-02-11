//
// Created by danie on 2/8/2024.
//
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

std::vector<int> reverseVector(std::vector<int> vectorToReverse) {
    std::vector<int> reversedVector(vectorToReverse.size());
    for (int i = 0; i < vectorToReverse.size(); i++) {
        reversedVector.at(i) = vectorToReverse.at(vectorToReverse.size() - i - 1);
    }
    return reversedVector;
}

std::string printIntVector(std::vector<int> &vectorToPrint) {
    std::string out;
    for (int &it: vectorToPrint) {
        out += std::to_string(it);
    }
    return out;
}

std::vector<int> toBinary(unsigned long long decimalIn) {
    std::vector<int> binaryVector;
    for (unsigned long long n = decimalIn; n > 0; n /= 2) {
        binaryVector.push_back((int) (n % 2));
    }
    binaryVector = reverseVector(binaryVector);
    return binaryVector;
}

unsigned long long toDecimal(std::string binaryIn) {
    unsigned long long decimalOut = 0;
    for (size_t i = binaryIn.size(); i > 0; i--) {
        int num = binaryIn.at(binaryIn.size() - i) - 48;
        decimalOut += (num) * ((unsigned long long) pow(2, (double) i - 1));
    }
    return decimalOut;
}

int main() {
    unsigned long long decimalIn;
    std::cout << "Please enter a positive number to convert to binary (up to " << ULLONG_MAX << "): ";
    std::cin >> decimalIn;

    std::vector<int> binaryVector = toBinary(decimalIn);
    std::string binary = printIntVector(binaryVector);
    std::cout << "Binary:\t\t\t\t" << binary << "\n";

    std::cout << "Back to decimal:\t" << toDecimal(binary) << "\n";

    //std::cout << "\t\t\t\t\t" << decimalIn;
    return 0;
}