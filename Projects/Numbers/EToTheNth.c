#include <stdio.h>
#include <math.h>
#include <limits.h>

double calculateE(){
    return pow(1.0 + (1.0/ULONG_MAX), ULONG_MAX);
}

int main(){
    int MaxDigits;
    printf("\nMax digits: ");
    scanf("%d", &MaxDigits);
    printf("\nValue of e is %.*f\n\n", MaxDigits, calculateE());
    return 0;
}