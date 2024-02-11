//
// Created by daniel on 2/11/24.
// Description: Enter a number and have the program generate PI up to that many decimal places. Keep a limit to how far the program will go.
//
#include "iostream"
#include "iomanip"

bool isEven(int n) {
    if (n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

double calculatePiNilakantha(int n) {
    double result = 3;
    int j = 2;
    for (int i = 1; i < n; i++) {
        int denominator = (j) * (j + 1) * (j + 2);
        //std::cout << denominator << " ";
        if (!isEven(i)) {
            result += 4.0 / denominator;
        } else {
            result -= 4.0 / denominator;
        }

        j = j + 2;
    }

    return result;
}

double calculatePiGregoryLeibniz(int n){
    double result = 1.0;
    int it=0;
    for(int i = 3; i < (n * 2) + 3; i += 2){
        int denominator = i;
        if(isEven(it)){
            result -= (1.0 / denominator);
        }else{
            result += (1.0 / denominator);
        }
        it++;
        //std::cout << "1/" << denominator << "="<< result << "\n";
    }

    result *= 4.0;
    return result;
}

int main() {
    int n = 3000000;
    std::cout << "Precision: ";
    std::cin >> n;

    // As N goes up, accuracy decreases (has to do with (j * j+1 * j+2) causing integer overflow)
    std::cout << std::setprecision(15) << calculatePiNilakantha(n) << "\n";

    // As N goes up, accuracy increases
    std::cout << std::setprecision(15) << calculatePiGregoryLeibniz(n) << "\n";
}