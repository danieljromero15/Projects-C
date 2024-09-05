//
// Created by danie on 9/4/2024.
//

#include <stdio.h>
#include <stdlib.h>

const int MAX_BINARY_LENGTH = 50;

int strLength(const char* strToFindLength){
    int length = 0;
    while(strToFindLength[length] != '\0'){
        length++;
    }
    return length;
}

void reverseStr(char* strToReverse){

    int length = strLength(strToReverse);
    for(int i = 0; i < (length / 2); i++){
        char last = strToReverse[length - i - 1];
        char first = strToReverse[i];
        strToReverse[i] = last;
        strToReverse[length - i - 1] = first;
    }
    //printf("\n%s", strToReverse);
}

void toBinary(unsigned long numToConvert, char *numStr){
    printf("\n%ld %s", numToConvert, numStr);
    int numStrIndex = 0;
    while(numToConvert > 0){
        if (numToConvert % 2 != 0){
            numStr[numStrIndex] = '1';
        }else{
            numStr[numStrIndex] = '0';
        }
        numStrIndex++;
        numToConvert = numToConvert / 2;
    }
    numStr[numStrIndex] = '\0';
    reverseStr(numStr);
}

int main(){
    unsigned long numToConvert;
    char binaryVal[MAX_BINARY_LENGTH];
    char numInput[20];
    char* endptr;
    printf("Please enter a number to convert to binary: ");
    fgets(numInput, sizeof(numInput), stdin);
    numToConvert = strtoul(numInput, &endptr, 10);
    printf("\nConverting %ld to binary", numToConvert);
    toBinary(numToConvert, (char *) &binaryVal);
    printf("\n%ld in binary is %s", numToConvert, binaryVal);
}