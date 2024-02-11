//
// Created by daniel on 2/11/24.
// Description: Have the program find prime numbers until the user chooses to stop asking for the next one.
//

#include <iostream>

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            //std::cout << n << "%" << i << "=" << n % i << " " << n << "\n";
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Press CTRL-C to stop\nPress Enter to proceed\n";
    int n = 0;
    while(true) { // very bad and hacky implementation but I'll learn how to detect key presses later
        if (isPrime(n)) {
            std::cout << n;
            std::cin.get();
        }
        n++;
    }
    return 0;
}