//
// Created by danie on 3/26/2024.
//
// Product Inventory Project - Create an application which manages an inventory of products.
// Create a product class which has a price, id, and quantity on hand.
// Then create an inventory class which keeps track of various products and can sum up the inventory value.

#include <iostream>
#include <vector>
#include "inventory.h"

// It's not 100% functional but that purely comes down to how much I want to mess with random numbers.
// To be clear, I don't want to mess with random numbers.
int main() {
    std::vector<product> inventory;

    inventory.reserve(100);
    for (int i = 0; i < 100; ++i) {
        inventory.emplace_back(9.99, i, 10);
    }

    std::cout << printProduct(inventory, "\n") << std::endl;

    std::cout << "Total inventory: " << productSum(inventory) << std::endl;

    return 0;
}