#include "stdio.h"

typedef struct{ //structure to hold the data
    int *array;
    size_t size;
} array_struct;

array_struct test()
{
    static int states[2] = {4, 7};
    array_struct array = {.array = states, .size = 2}; //assing pointer and size
    return array; //return the structure
}

int main()
{
    array_struct values = test(); //assing the structure to a local

    for(size_t i = 0; i < values.size; i++){ //use the size passed
        printf("%d ", values.array[i]);
    }
}