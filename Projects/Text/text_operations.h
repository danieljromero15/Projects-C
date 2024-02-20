//
// Created by danie on 2/20/2024.
//

#include <string>

#ifndef PROJECTS_TEXT_OPERATIONS_H
#define PROJECTS_TEXT_OPERATIONS_H

#endif //PROJECTS_TEXT_OPERATIONS_H

//Reverse a String - Enter a string and the program will reverse it and print it out.
std::string reverseString(std::string stringToReverse){
    std::string reversedString(stringToReverse.length(), ' ');
    for(int i = 0; i < stringToReverse.length(); i++){
        reversedString[i] = stringToReverse[stringToReverse.length() - i - 1];
    }
    return reversedString;
}