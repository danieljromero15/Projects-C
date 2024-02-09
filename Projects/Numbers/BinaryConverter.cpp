//
// Created by danie on 2/8/2024.
//
#include <iostream>
#include "vector"

std::vector<int> toBinary(int max) {
    std::vector<int> binaryArray;
    for(int i = 0; i < max; i++){
        binaryArray.push_back(i);
    }
    return binaryArray;
}

int main() {
    std::vector<int> binaryArray = toBinary(5);
    //for(int i = 0; i < &binaryArray)
    //std::cout << sizeof(binaryArray); // this doesn't work, make an object
    //std::cout << "\n";
    for (auto it = binaryArray.begin(); it != binaryArray.end(); it++) {
        std::cout << *it;
    }
    return 0;
}