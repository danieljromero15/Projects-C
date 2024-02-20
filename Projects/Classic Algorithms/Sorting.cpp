//
// Created by danie on 2/13/2024.
// Description: Implement two types of sorting algorithms: Merge sort and bubble sort.
//

#include <vector>
#include <iostream>
#include "../.headers/printCollections.h"

using std::vector;

template <class T>
vector<T> mergeSort(vector<T> toSort){
    vector<T> sorted;
    for(int i = 0; i < toSort.size(); i += 2){
        if(i + 1 >= toSort.size()){
            sorted.push_back(toSort[i]);
            break;
        }
        if(toSort[i] < toSort[i + 1]){
            sorted.push_back(toSort[i]);
            sorted.push_back(toSort[i + 1]);
        }else{
            sorted.push_back(toSort[i+1]);
            sorted.push_back(toSort[i]);
        }
    }

    return sorted;
}

int main(){
    vector<int> arrayToSort = {6, 5, 3, 1, 8, 7, 2, 4, 10};

    vector<int> sortedArray = mergeSort(arrayToSort);

    std::cout << printVector<int>(sortedArray, " ") << std::endl;

    return 0;
}