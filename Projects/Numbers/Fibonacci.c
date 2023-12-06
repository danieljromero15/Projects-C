#include <stdio.h>
#include <stdlib.h>

// Fibonacci.cquence
int i = 1;

void printFibonacci(int f0, int f1, int maxIndex) {
    if (!(f0 == 0 || i > maxIndex)) {
        i++;
        printf("%d ", f1);
        printFibonacci(f1, f0 + f1, maxIndex);
    } else if (f0 == 0) {
        i++;
        printf("%d %d ", f0, f1);
        printFibonacci(f1, f0 + f1, maxIndex);
    } else {
        exit(0);
    }
}

int main() {
    int max;
    printf("\nMax index: ");
    scanf("%d", &max);

    printFibonacci(0, 1, max);

    printf("\n\n");

    return 0;
}