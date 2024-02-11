//
// Created by daniel on 2/11/24.
// Description: The user enters a cost and then the amount of money given. The program will figure out the change and the number of quarters, dimes, nickels, pennies needed for the change.
//

#include <iostream>
#include <iomanip>
#include <cmath>

std::tuple<int, int, int, int> calculateChange(double value) {
    std::tuple<int, int, int, int> change = std::make_tuple(0, 0, 0, 0);
    int* quarters =     &std::get<0>(change);
    int* dimes =        &std::get<1>(change);
    int* nickels =      &std::get<2>(change);
    int* pennies =      &std::get<3>(change);


    double remainder = fmodf( (float) value, 0.25);
    *quarters = (int) ((value - remainder) / 0.25);




    std::cout << remainder << " " << *quarters << " " << 0.5 / 0.25 << "\n";

    return change;
}

std::string printResults(std::tuple<int, int, int, int> tupleToPrint) {
    std::string out;
    int quarters = std::get<0>(tupleToPrint);
    int dimes = std::get<1>(tupleToPrint);
    int nickels = std::get<2>(tupleToPrint);
    int pennies = std::get<3>(tupleToPrint);

    out += "Quarters: " + std::to_string(quarters) + "\n";
    out += "Dimes: " + std::to_string(dimes) + "\n";
    out += "Nickels: " + std::to_string(nickels) + "\n";
    out += "Pennies: " + std::to_string(dimes) + "\n";

    double total =
            (quarters * 0.25) +
            (dimes * 0.10) +
            (nickels * 0.05) +
            (pennies * 0.01);

    out += "\nTotal: " + std::to_string(total) + "\n";
    return out;
}

int main() {
    double dollarValue = 0.64;
    std::tuple<int, int, int, int> results = calculateChange(dollarValue);
    std::cout << printResults(results);

    return 0;
}