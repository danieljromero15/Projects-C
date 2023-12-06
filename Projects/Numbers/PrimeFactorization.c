#include <stdio.h>

void printIntArray(int *arrayToPrint, int sizeOfArray){
    for(int i = 0; i < sizeOfArray / 4; ++i){
        printf("%d ", (*arrayToPrint + i));
    }
}

int main(){
    int numberToFind;

    printf("Please enter the number for which to find the Prime Factors: ");
    scanf("%d", &numberToFind);

    int array[] = {1, 2, 3, 4, 5};
    printIntArray(array, sizeof(array));

    return 0;
}