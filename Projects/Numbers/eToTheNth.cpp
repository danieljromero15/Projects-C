//
// Created by daniel on 2/11/24.
// Description: Just like the previous problem, but with e instead of PI. Enter a number and have the program generate e up to that many decimal places. Keep a limit to how far the program will go.
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

unsigned long long factorial(int n){
    unsigned long long result = 1;

    if(n == 0){
        return result;
    }else{
        for(int i = 1; i <= n; i++){
            result *= i;
        }
        return result;
    }
}

double calculateE(int n){
    double e;
    for(int i = 0; i <= n; i++){
        e += (double) (1.0 / (long double) factorial(i));
        //std::cout << i << " 1.0 / " << factorial(i) << "\t\t" << e << "\n";
    }

    return e;
}

int main() {
    int n = 65;
    std::cout << "Precision (max 65): ";
    std::cin >> n;

    std::cout << std::setprecision(15) << calculateE(n) << "\n";
}