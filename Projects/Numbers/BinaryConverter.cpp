//
// Created by danie on 2/8/2024.
//
#include <iostream>

int* toBinary(int decimalNumberInput){
    int binaryArray[] = {1, 2, 3,4};
    return &binaryArray[0];
}

int main(){
    int *binaryArray = toBinary(2);
    //for(int i = 0; i < &binaryArray)
    std::cout << sizeof(binaryArray); // this doesn't work, make an object
    std::cout << "\n";
    std::cout << toBinary(2);
    return 0;
}