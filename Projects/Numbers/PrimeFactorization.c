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
        isPrimeBool = false;
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
            product *= *(ArrayToMultiply + i);
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
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            factors.intArray[factors.intArraySize] = i;
            ++factors.intArraySize;
            // factors.intArray = resizeAndClearArray(factors.intArraySize);
        }
    }
    return factors;
}

/*int* primeFactorizationRecursion(int n1, int n2, int* arrayToAddTo, int
index){ if(isPrime(n1)){ arrayToAddTo[index] = n1;
        ++index;
    }

    if(!isPrime(n2)){
        int newPrime = n2 / factorization(n2).intArray[0];
        arrayToAddTo = primeFactorizationRecursion(newPrime, n2 / newPrime,
arrayToAddTo, index); }else if(isPrime(n2)){ arrayToAddTo[index + 1] = n2;
    }else{
        printf("\nError\n");
        exit(0);
    }

    printIntArray(arrayToAddTo, index);

    return arrayToAddTo;
}*/

struct integerArray primeFactorization(int startNum) {
    if(isPrime(startNum)){
        printf("%d is already prime!\n", startNum);
        exit(0);
    }else if(startNum < 2){
        printf("Please enter a positive number greater than 2.\n");
        exit(0);
    }

    struct integerArray primeFactors;

    int *factorArray = factorization(startNum).intArray;
    int factorArraySize = factorization(startNum).intArraySize;

    // printf("%d", factorArraySize);

    primeFactors.intArray = resizeAndClearArray(startNum * 8);
    //primeFactors.intArray = resizeAndClearArray(1024);

    int n1 = factorArray[0];
    int n2 = factorArray[factorArraySize - 1];

    printf("factors: %d %d\n", n1, n2);

    primeFactors.intArraySize = 1;
    primeFactors.intArray[0] = n1;

    int index1, index2;

    while (!isPrime(n2)){
        index1 = primeFactors.intArraySize;
        index2 = ++primeFactors.intArraySize;

        primeFactors.intArray[index1] = n1;
        primeFactors.intArray[index2] = n2;

        printf("primeFactors: ");
        printIntArray(primeFactors.intArray, primeFactors.intArraySize + 1);
        //printf("index2:%d", primeFactors.intArray[index2]);

        factorArray = factorization(n2).intArray;
        factorArraySize = factorization(n2).intArraySize;

        printf("factorArray: ");
        printIntArray(factorArray, factorArraySize);

        n1 = factorArray[0];
        n2 = factorArray[factorArraySize - 1];

        primeFactors.intArray[index2] = n1;
        primeFactors.intArray[index2 + 1] = n2;

        //printf("n2:%d", n2);

    }

    primeFactors.intArray[primeFactors.intArraySize] = n2;
    //primeFactors.intArray[index2 + 2] = n2;
    ++primeFactors.intArraySize;
    //  primeFactors.intArray = primeFactorizationRecursion(factorArray[0],
    //  factorArray[factorArraySize - 1], primeFactors.intArray, 0);

    printf("\nfinal: ");
    printIntArray(primeFactors.intArray, primeFactors.intArraySize);
    printf("\nProduct: %d",
           multiplyIntArray(primeFactors.intArray, primeFactors.intArraySize));
    printf("\n");

    return primeFactors;
}

int main() {
    int numberToFind;

    printf("Please enter the number for which to find the Prime Factors: ");
    scanf("%d", &numberToFind);

    // printf("%d", primeNumsBefore(numberToFind));
    /*struct integerArray primeNumArray = primeNumsBefore(numberToFind);
    printIntArray(primeNumArray.intArray, primeNumArray.intArraySize);

    printf("\n");

    struct integerArray factorsArray = factorization(numberToFind);
    printIntArray(factorsArray.intArray, factorsArray.intArraySize);

    printf("\n");*/

    struct integerArray primeFactorsArray = primeFactorization(numberToFind);
    printIntArray(primeFactorsArray.intArray, primeFactorsArray.intArraySize);

    printf("\n");
    return 0;
}