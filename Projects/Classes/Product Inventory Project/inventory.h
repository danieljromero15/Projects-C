//
// Created by danie on 3/26/2024.
//

#ifndef PROJECTS_INVENTORY_H
#define PROJECTS_INVENTORY_H


class product {
public:
    float price;
    int id;
    int quantity;

    product(float price, int id, int quantity) {
        this->price = price;
        this->id = id;
        this->quantity = quantity;
    }
};


std::string printProduct(std::vector<product> &vectorToPrint, const std::string &separator){
    std::string out;
    for(product &it: vectorToPrint){
        out += std::to_string(it.price) + ' ' + std::to_string(it.id) + ' ' + std::to_string(it.quantity) + separator;
    }
    return out;
}

int productSum(std::vector<product> &productVector){
    int sum = 0;
    for(product &it : productVector){
        sum += it.quantity;
    }
    return sum;
}

#endif //PROJECTS_INVENTORY_H
