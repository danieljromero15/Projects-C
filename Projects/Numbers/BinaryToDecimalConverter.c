//
// Created by daniel on 2/6/2024.
//

//Develop a converter to convert a decimal number to binary or a binary number to its decimal equivalent.

#include <stdio.h>
#include <math.h>

struct IntArray {
    int arrayLength;
    int array[];
};

void printIntArray(const int *arrayToPrint, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d ", *(arrayToPrint + i));
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


int *convertToBinary(int decimalNumber) {
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


        printf("\nfinal:\n");
        printIntArray(resultArr, resultArrLength);

        printf("\n");

        //printIntArray(reverseIntArray(resultArr, resultArrLength), resultArrLength);

        return resultArr;

    } else if (decimalNumber < 0) {
        printf("\nnegative numbers not implemented yet\n");
        return 0;
    } else {
        return 0;
    }

    return 0;
}

int main() {
    int numberToConvert = 0;
    int result;
    printf("Please input a number to convert to binary: ");
    //scanf("%d", &numberToConvert);

    printf("\n\n%lu", convertToBinary(42)); //should be 32 8 2

    //result = convertToBinary(numberToConvert);
    //printf("\nOutput: %d", result);

    return 0;
}