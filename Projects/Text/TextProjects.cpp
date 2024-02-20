//
// Created by danie on 2/20/2024.
//

#include <iostream>
#include "../.headers/text_operations.h"
#include "../.headers/printCollections.h"

int main(int argc, char *argv[]) {
    std::string word = "Hello";
    if (argc >= 2) {
        // cmdline arguments var definition go here
        word = std::string(argv[1]);
    }

    std::cout << "Word is: " << word << std::endl;

    std::cout << "Reversed: " << reverseString(word) << std::endl;

    std::cout << "Pig latin: " << pigLatin(word) << std::endl;

    std::array<int, 5> vowelsCountArray = vowelsCount(word);
    std::cout << "Vowels count: " << printArray<5>(vowelsCountArray, " ") << std::endl;
    std::cout << "\ta: " << vowelsCountArray[0] << "\n\te: " << vowelsCountArray[1] << "\n\ti: " << vowelsCountArray[2] << "\n\to: " << vowelsCountArray[3] << "\n\tu: " << vowelsCountArray[4] << std::endl;

    return 0;
}