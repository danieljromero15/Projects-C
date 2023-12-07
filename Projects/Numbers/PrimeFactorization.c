#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct integerArray {
    int *intArray;
    int intArraySize;
};

int *resizeAndClearArray(int size) { return (int *)malloc(sizeof(int) * size); }

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

    // printf("\n");
    return isPrimeBool;
}

// prints integer array
void printIntArray(int *arrayToPrint, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%d ", *(arrayToPrint + i));
    }
}

long multiplyIntArray(int *ArrayToMultiply, int sizeOfArray) {
    long product = 1;

    if (sizeOfArray == 0) {
        product = 0;
    } else {
        for (int i = 0; i < sizeOfArray; i++) {
            product *= (*ArrayToMultiply + i);
        }
    }

    return product;
}

// calculates all prime numbers before the startNum
struct integerArray primeNumsBefore(int startNum) {
    struct integerArray primeArray;
    primeArray.intArray = resizeAndClearArray(startNum);
    primeArray.intArraySize = 0;
    for (int i = 2; i < startNum; ++i) {
        // printf("%d", i);
        if (isPrime(i)) {
            // printf("is prime, adding to index %d", n);
            primeArray.intArray[primeArray.intArraySize] = i;
            // printf("\t%d\n", primeArray[n]);
            ++primeArray.intArraySize;
        } else {
            // printf("is not prime\n");
        }
    }
    // printIntArray(primeArray.intArray, primeArray.intArraySize);
    // printf("\n");
    return primeArray;
}

struct integerArray factorization(int n) {
    struct integerArray factors;
    
    factors.intArray = resizeAndClearArray(n);
    factors.intArraySize = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            factors.intArray[factors.intArraySize] = i;
            ++factors.intArraySize;
            //factors.intArray = resizeAndClearArray(factors.intArraySize);
            
        }
    }
    return factors;
}

struct integerArray primeFactorization(int startNum) {
    struct integerArray primeFactors;

    int *factorArray = factorization(startNum).intArray;
    int factorArraySize = factorization(startNum).intArraySize;

    printf("%d", factorArraySize);

    primeFactors.intArray = resizeAndClearArray(startNum * 8);

    primeFactors.intArraySize = 0;
    primeFactors.intArray[0] = 0;
    /*if (!isPrime(startNum)) { // this entire thing needs to be changed to its own recursive function
        //while (multiplyIntArray(primeFactors.intArray, primeFactors.intArraySize) != startNum) {
        while (primeFactors.intArraySize < 10) {
            //printf("product: %d\n", multiplyIntArray(primeFactors.intArray, primeFactors.intArraySize));
            primeFactors.intArray[primeFactors.intArraySize] = factorArray[1];

            if(!isPrime(factorArray[factorArraySize - 1])){

            }


            ++primeFactors.intArraySize;

            //printIntArray(primeFactors.intArray, primeFactors.intArraySize);
        }
    } else {
        primeFactors.intArray[primeFactors.intArraySize] = startNum;
        printf("\nYour number is already prime!");
        exit(0);
    }*/

    printf("\nfinal: ");
    printIntArray(primeFactors.intArray, primeFactors.intArraySize);
    printf("\n");

    return primeFactors;
}

int main() {
    int numberToFind;

    printf("Please enter the number for which to find the Prime Factors: ");
    scanf("%d", &numberToFind);

    // printf("%d", primeNumsBefore(numberToFind));
    // struct integerArray primeNumArray = primeNumsBefore(numberToFind);
    // printIntArray(primeNumArray.intArray, primeNumArray.intArraySize);

    printf("\n");

    struct integerArray factorsArray = factorization(numberToFind);
    printIntArray(factorsArray.intArray, factorsArray.intArraySize);

    printf("\n");

    struct integerArray primeFactorsArray = primeFactorization(numberToFind);
    printIntArray(primeFactorsArray.intArray, primeFactorsArray.intArraySize);

    printf("\n");
    return 0;
}