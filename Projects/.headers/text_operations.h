//
// Created by danie on 2/20/2024.
//

#include <string>
#include <array>
#include <utility>
#include <vector>

#ifndef PROJECTS_TEXT_OPERATIONS_H
#define PROJECTS_TEXT_OPERATIONS_H

#endif //PROJECTS_TEXT_OPERATIONS_H

using std::string;

bool isVowel(char c) {
    const string vowels = "aeiouAEIOU";
    if (vowels.find(c) != string::npos) {
        return true;
    } else {
        return false;
    }
}

string toLower(string word) {
    for (int i = 0; i < word.length(); i++) { // converts whole word to lowercase
        word[i] = (char) tolower(word[i]);
    }
    return word;
}

std::vector<string> sentenceToVector(string sentence) {
    std::string word;
    std::vector<string> output;

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            word += sentence[i];
        } else {
            output.push_back(word);
            word = "";
        }
    }
    if (!word.empty()) {
        output.push_back(word);
    }
    return output;
}

// Count Words in a String - Counts the number of individual words in a string.
// For added complexity read these strings in from a text file and generate a summary.

int numOfWords(string sentence){
    std::vector<string> sentenceVector = sentenceToVector(std::move(sentence));
    return (int)sentenceVector.size();
}

//Reverse a String - Enter a string and the program will reverse it and print it out.
string reverseString(string stringToReverse) {
    string reversedString(stringToReverse.length(), ' ');
    for (int i = 0; i < stringToReverse.length(); i++) {
        reversedString[i] = stringToReverse[stringToReverse.length() - i - 1];
    }
    return reversedString;
}

//Pig Latin - Pig Latin is a game of alterations played on the English language game.
// To create the Pig Latin form of an English word the initial consonant sound is transposed to the end of the word and an ay is affixed (Ex.: "banana" would yield anana-bay).
// Read Wikipedia for more information on rules.

string pigLatin(string toTranslate) {
    toTranslate = toLower(toTranslate);
    std::vector<string> words = sentenceToVector(toTranslate);
    std::string out;

    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        if (isVowel(word[0])) {
            word += "way";
        } else {
            char temp = word[0];
            word = word.substr(1, toTranslate.length());
            //std::cout << toTranslate << std::endl;
            word += temp;
            word += "ay";
        }
        words[i] = word;
    }
    //std::cout << isVowel(toTranslate[0]) << std::endl;

    for(string &it: words){
        out += it + " ";
    }

    return out;
}

// Count Vowels - Enter a string and the program counts the number of vowels in the text.
// For added complexity have it report a sum of each vowel found.

std::array<int, 5> vowelsCount(string word) {
    std::array vowels = {0, 0, 0, 0, 0};
    word = toLower(word);

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

// Check if Palindrome - Checks if the string entered by the user is a palindrome.
// That is that it reads the same forwards as backwards like “racecar”

bool isPalindrome(string word) {
    word = toLower(word);
    for (int i = 0; i < word.length() / 2; i++) {
        //std::cout << "comparing " << word[i] << " and " << word[word.length() - i - 1] << std::endl;
        if (word[i] != word[word.length() - i - 1]) {
            return false;
        }
    }
    return true;
}