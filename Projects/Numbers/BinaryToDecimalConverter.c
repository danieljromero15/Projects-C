//
// Created by daniel on 2/6/2024.
//

//Develop a converter to convert a decimal number to binary or a binary number to its decimal equivalent.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct intArray {
    int array[10];
    int length;
};

void printIntArray(const int *arrayToPrint, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d", *(arrayToPrint + i));
    }
}

void printIntArrayStruct(struct intArray arrayToPrint) {
    printf("\t");
    for (int i = 0; i < arrayToPrint.length; i++) {
        printf("%d", *(arrayToPrint.array + i));
    }
}

int *reverseIntArray(const int *intArrayToReverse, int intArrayToReverseLength) { //will return pointer
    int reversedArray[intArrayToReverseLength];
    int intArrayToReverseLengthTemp = intArrayToReverseLength;

    for (int i = 0; i < intArrayToReverseLength; i++) {
        reversedArray[i] = intArrayToReverse[--intArrayToReverseLengthTemp];
    }

    printIntArray(reversedArray, intArrayToReverseLength);

    return &reversedArray[0];
}

unsigned long long longPow(int base, int power) {
    unsigned long long final = base;
    for (int i = 1; i < power; i++) {
        final *= base;
    }
    return final;
}

unsigned long long arrayToInt(const int *arrayToConvert, int arrayToConvertSize) { // works up to 1048575
    unsigned long long out = 0;
    unsigned long long numberOfZeroes = longPow(10, arrayToConvertSize - 1);
    for (int i = 0; i < arrayToConvertSize; i++) {
        out += arrayToConvert[i] * numberOfZeroes;
        numberOfZeroes /= 10;
    }

    return out;
}

int lenHelper(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000) return 9;
    if (x >= 10000000) return 8;
    if (x >= 1000000) return 7;
    if (x >= 100000) return 6;
    if (x >= 10000) return 5;
    if (x >= 1000) return 4;
    if (x >= 100) return 3;
    if (x >= 10) return 2;
    return 1;
}

struct intArray splitIntIntoArray(unsigned long long intToSplit) {
    int intToSplitLength = lenHelper(intToSplit);
    struct intArray arrayToSplit;



    arrayToSplit.length = intToSplitLength;
    //printf("m%d", arrayToSplit.length);
    for(int i = arrayToSplit.length; i >= 0; i--){

        arrayToSplit.array[i] = (int) intToSplit % 10;
        intToSplit /= 10;

    }

    arrayToSplit.length = intToSplitLength;
    //printf("n%d", arrayToSplit.length);


    return arrayToSplit;
}

unsigned long long convertToBinary(int decimalNumber) {
    int result = decimalNumber;
    int resultArrLength = 0;
    int resultArrLengthTemp;

    //define array size
    while (result > 0) {
        result /= 2;
        resultArrLength++;
    }
    int resultArr[resultArrLength];

    result = decimalNumber;
    resultArrLengthTemp = resultArrLength - 1;
    while (result > 0) {
        //printf("%d ", result % 2);
        resultArr[resultArrLengthTemp] = result % 2;
        result /= 2;
        resultArrLengthTemp--;
    }


    //printf("\nfinal:\narr\t");
    //printIntArray(resultArr, resultArrLength);

    //printf("\n");

    //printIntArray(reverseIntArray(resultArr, resultArrLength), resultArrLength);
    //printf("int\t%llu", arrayToInt(resultArr, resultArrLength));

    return arrayToInt(resultArr, resultArrLength);
}

int main() {
    int numberToConvert = 0;
    printf("Please input a positive number to convert to binary (up to 1048575): ");
    scanf("%u", &numberToConvert);

    if (numberToConvert > 1048575) {
        printf("\nPlease enter a number less than 1048575");
        exit(0);
    }
    else {

        unsigned long long result = convertToBinary(numberToConvert);
        printf("\nBinary:\t%llu", result);
        //printf("\n%d", splitIntIntoArray(result));
        printf("\n");
        struct intArray resultStruct = splitIntIntoArray(result);
        //printf("\no%d\n", resultStruct.length);
        printIntArrayStruct(resultStruct);

        //result = convertToBinary(numberToConvert);
        //printf("\nOutput: %d", result);
    }
    return 0;
}