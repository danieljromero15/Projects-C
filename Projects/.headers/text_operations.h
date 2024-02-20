//
// Created by danie on 2/20/2024.
//

#include <string>
#include <array>

#ifndef PROJECTS_TEXT_OPERATIONS_H
#define PROJECTS_TEXT_OPERATIONS_H

#endif //PROJECTS_TEXT_OPERATIONS_H

//Reverse a String - Enter a string and the program will reverse it and print it out.
std::string reverseString(std::string stringToReverse) {
    std::string reversedString(stringToReverse.length(), ' ');
    for (int i = 0; i < stringToReverse.length(); i++) {
        reversedString[i] = stringToReverse[stringToReverse.length() - i - 1];
    }
    return reversedString;
}

//Pig Latin - Pig Latin is a game of alterations played on the English language game.
// To create the Pig Latin form of an English word the initial consonant sound is transposed to the end of the word and an ay is affixed (Ex.: "banana" would yield anana-bay).
// Read Wikipedia for more information on rules.

bool isVowel(char c) {
    const std::string vowels = "aeiouAEIOU";
    if (vowels.find(c) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

std::string stringToLower(std::string word) {
    for (int i = 0; i < word.length(); i++) { // converts whole word to lowercase
        word[i] = (char) tolower(word[i]);
    }
    return word;
}

std::string pigLatin(std::string word) {
    word = stringToLower(word);
    //std::cout << isVowel(word[0]) << std::endl;
    if (isVowel(word[0])) {
        word += "way";
    } else {
        char temp = word[0];
        word = word.substr(1, word.length());
        //std::cout << word << std::endl;
        word += temp;
        word += "ay";
    }

    return word;
}

// Count Vowels - Enter a string and the program counts the number of vowels in the text.
// For added complexity have it report a sum of each vowel found.

std::array<int, 5> vowelsCount(std::string word) {
    std::array vowels = {0, 0, 0, 0, 0};
    word = stringToLower(word);

    for (char c: word) {
        if (isVowel(c)) {
            switch (c) {
                case 'a':
                    vowels[0]++;
                    break;
                case 'e':
                    vowels[1]++;
                    break;
                case 'i':
                    vowels[2]++;
                    break;
                case 'o':
                    vowels[3]++;
                    break;
                case 'u':
                    vowels[4]++;
                    break;
                default:
                    break;
            }
        }
    }
    return vowels;
}