#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int startNum) {  // just calculates if the number is prime
    bool isPrimeBool = true;
    if (startNum > 1) {
        for (int i = 2; i < startNum; ++i) {
            if (startNum % i == 0) {
                isPrimeBool = false;
                break;
            }
        }
    } else {
        printf("\nPlease provide a number greater than 1\n");
        exit(0);
    }

    printf("\n");
    return isPrimeBool;
}

void printIntArray(int *arrayToPrint,
                   int sizeOfArray) {  // prints integer array
    for (int i = 0; i < sizeOfArray / 4; ++i) {
        printf("%d ", (*arrayToPrint + i));
    }
}

long multiplyIntArray(int *ArrayToMultiply, int sizeOfArray) {
    int n = sizeOfArray / 4;
    long product = 1;

    if (n == 0) {
        product = 0;
    } else {
        for (int i = 0; i < n; i++) {
            product *= (*ArrayToMultiply + i);
        }
    }

    return product;
}

int primeArray(int StartNum){ // calculates all prime numbers before the startNum
    
}

struct factorsStruct {
    int factorsArrayLen;
    int factorsArray[255];
};

struct factorsStruct primeFactorization(int startNum) {
    struct factorsStruct s1;

    s1.factorsArrayLen = 0;
    for (int i = 1; i < startNum; ++i) {
        if (startNum % i == 0) {
            s1.factorsArray[s1.factorsArrayLen] = i;
            s1.factorsArrayLen++;
        }
    }

    printf("%d", s1.factorsArray[0]);

    return s1;
}

int main() {
    int numberToFind;

    printf("Please enter the number for which to find the Prime Factors: ");
    scanf("%d", &numberToFind);

    printIntArray(primeFactorization(numberToFind).factorsArray,
                  primeFactorization(numberToFind).factorsArrayLen);

    printf("\n");
    return 0;
}