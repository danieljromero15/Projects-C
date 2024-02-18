//
// Created by danie on 2/13/2024.
// Description: Write a program that prints the numbers from 1 to 100.
//      But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”.
//      For numbers which are multiples of both three and five print “FizzBuzz”.
//

#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        std::string out;
        if (i % 3 == 0) {
            out += "Fizz";
        }
        if (i % 5 == 0) {
            out += "Buzz";
        }

        if (out.empty()) {
            out += std::to_string(i);
        }

        std::cout << out << "\n";
    }

    return 0;
}