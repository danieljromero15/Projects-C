//
// Created by daniel on 2/6/2024.
//

//Develop a converter to convert a decimal number to binary or a binary number to its decimal equivalent.

#include <stdio.h>
#include <math.h>

void printIntArray(const int *arrayToPrint, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d", *(arrayToPrint + i));
    }
}

int *reverseIntArray(const int *intArrayToReverse, int intArrayToReverseLength){ //will return pointer
    int reversedArray[intArrayToReverseLength];
    int intArrayToReverseLengthTemp = intArrayToReverseLength;

    for(int i=0; i < intArrayToReverseLength; i++){
        reversedArray[i] = intArrayToReverse[--intArrayToReverseLengthTemp];
    }

    printIntArray(reversedArray, intArrayToReverseLength);

    return &reversedArray[0];
}

unsigned long long longPow(int base, int power){
    unsigned long long final = base;
    for(int i=1; i < power; i++){
        final *= base;
    }
    return final;
}

unsigned long long arrayToInt(const int *arrayToConvert, int arrayToConvertSize){ // works up to 1048575
    unsigned long long out = 0;
    unsigned long long numberOfZeroes = longPow(10, arrayToConvertSize - 1);
    for(int i=0; i < arrayToConvertSize; i++){
        out += arrayToConvert[i] * numberOfZeroes;
        numberOfZeroes /= 10;
    }

    return out;
}

unsigned long long convertToBinary(int decimalNumber) {
    int result = decimalNumber;
    int resultArrLength=0;
    int resultArrLengthTemp;

    if (decimalNumber > 0) {
        //define array size
        while (result > 0){
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

    } else if (decimalNumber < 0) {
        printf("\nnegative numbers not implemented yet\n");
        return 0;
    } else {
        return 0;
    }
}

int main() {
    int numberToConvert = 0;
    printf("Please input a number to convert to binary (up to 1048575): ");
    scanf("%d", &numberToConvert);

    printf("\nBinary: %llu", convertToBinary(numberToConvert));

    //result = convertToBinary(numberToConvert);
    //printf("\nOutput: %d", result);

    return 0;
}