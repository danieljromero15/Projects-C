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

//Pig Latin - Pig Latin is a game of alterations played on the English language game.
// To create the Pig Latin form of an English word the initial consonant sound is transposed to the end of the word and an ay is affixed (Ex.: "banana" would yield anana-bay).
// Read Wikipedia for more information on rules.

bool isVowel(char c){
    const std::string vowels = "aeiouAEIOU";
    if(vowels.find(c) != std::string::npos){
        return true;
    }else{
        return false;
    }
}

std::string pigLatin(std::string word){
    for(int i = 0; i < word.length(); i++){ // converts whole word to lowercase
        word[i] = (char)tolower(word[i]);
    }
    //std::cout << isVowel(word[0]) << std::endl;
    if(isVowel(word[0])){
        word += "way";
    }else{
        char temp = word[0];
        word = word.substr(1, word.length());
        std::cout << word << std::endl;
        word += temp;
        word += "ay";
    }

    return word;
}