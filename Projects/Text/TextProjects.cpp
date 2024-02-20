//
// Created by danie on 2/20/2024.
//

#include <iostream>
#include "../.headers/text_operations.h"
#include "../.headers/printCollections.h"

using std::cout;

int main(int argc, char *argv[]) {
    std::string word = "racecar is cool";
    if (argc >= 2) {
        // cmdline arguments var definition go here
        word = std::string(argv[1]);
    }

    cout << "Word is: " << word << std::endl;

    cout << "Reversed: " << reverseString(word) << std::endl;

    cout << "Pig latin: " << pigLatin(word) << std::endl;

    std::array<int, 5> vowelsCountArray = vowelsCount(word);
    cout << "Vowels count: " << printArray<5>(vowelsCountArray, " ") << std::endl;
    cout << "\ta: " << vowelsCountArray[0] << "\n\te: " << vowelsCountArray[1] << "\n\ti: " << vowelsCountArray[2]
         << "\n\to: " << vowelsCountArray[3] << "\n\tu: " << vowelsCountArray[4] << std::endl;

    cout << "Is " << word << " a palindrome? ";
    if (isPalindrome(word)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << std::endl;

    //std::vector<std::string> vectorSentence = sentenceToVector(word);
    //cout << printVector(vectorSentence, " ") << std::endl;

    std::cout << "Number of words: " << numOfWords(word);

    return 0;
}