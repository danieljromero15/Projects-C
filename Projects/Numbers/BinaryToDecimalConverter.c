//
// Created by danie on 9/4/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int MAX_BINARY_LENGTH = 50;

/*int strLength(const char* strToFindLength){
    int length = 0;
    while(strToFindLength[length] != '\0'){
        length++;
    }
    return length;
}*/

void reverseStr(char* strToReverse){
    int length = strlen(strToReverse); // error is here, length is not correct
    //printf("len of str %d", length);
    for(int i = 0; i < (length / 2); i++){
        char last = strToReverse[length - i - 1];
        char first = strToReverse[i];
        strToReverse[i] = last;
        strToReverse[length - i - 1] = first;
    }
    //printf("\nstrToReverse: %s\n", strToReverse);
}

void toBinary(unsigned long numToConvert, char *numStr){
    //printf("\n%ld %s", numToConvert, numStr);
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

void printStats(char* str){
    printf("\n%s, sizeof %llu\n", str, strlen(str));
}

unsigned long toDecimal(char *numStr){

    unsigned long long length = strlen(numStr);
    unsigned long result = 0;
    char numStrReversed[length];
    //char *endptr;

    //printf("\n%s, length %d, sizeof %llu\n", numStr, length, sizeof(numStr));
    //printStats(numStr);
    //memcpy(numStrReversed, numStr, length);
    strcpy(numStrReversed, numStr); // omg the solution was using strcpy instead of memcpy aaaaaaaaa
    //printStats(numStrReversed);
    reverseStr(numStrReversed);
    //printf("%s\t%s\n", numStr, numStrReversed);
    for(int i=0; i < length;i++){
        if(numStrReversed[i] == '1'){
            result += (unsigned long) pow(2, i);
        }
    }
    return result;
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

    unsigned long decimal = toDecimal(binaryVal);
    //printf("\nFinal result: %lu", decimal);
    printf("\nConverting %s back to decimal is %lu\n", binaryVal, decimal);
}