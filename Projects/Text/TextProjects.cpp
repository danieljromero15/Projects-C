//
// Created by danie on 2/20/2024.
//

#include <iostream>
#include "text_operations.h"

int main(int argc, char *argv[]) {
    std::string word = "Hello";
    if (argc >= 2) {
        // cmdline arguments var definition go here
        word = std::string(argv[1]);
    }

    std::cout << "Word is: " << word << std::endl;

    std::cout << "Reversed: " << reverseString(word) << std::endl;

    std::cout << "Pig latin: " << pigLatin(word) << std::endl;

    std::cout << "Vowels count: ";

    return 0;
}