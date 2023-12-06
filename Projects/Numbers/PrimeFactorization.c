#include <stdio.h>

void printIntArray(int *arrayToPrint, int sizeOfArray){
    for(int i = 0; i < sizeOfArray / 4; ++i){
        printf("%d ", (*arrayToPrint + i));
    }
}

struct factorsStruct{
    int factorsArrayLen;
    int factorsArray[255];
};


struct factorsStruct primeFactorization(int startNum){
    struct factorsStruct s1;

    s1.factorsArrayLen = 0;
    for(int i = 1; i < startNum; ++i){
        if(startNum % i == 0){
            s1.factorsArray[s1.factorsArrayLen] = i;
            s1.factorsArrayLen++;
        }
    }

    printf("%d", s1.factorsArray[0]);


    return s1;
}

int main(){
    int numberToFind;

    printf("Please enter the number for which to find the Prime Factors: ");
    scanf("%d", &numberToFind);

    printIntArray(primeFactorization(numberToFind).factorsArray, primeFactorization(numberToFind).factorsArrayLen);

    printf("\n");
    return 0;
}