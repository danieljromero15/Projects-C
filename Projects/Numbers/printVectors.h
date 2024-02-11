//
// Created by daniel on 2/11/24.
//
#include <cstdlib>
#include "vector"
#include "string"

#ifndef PROJECTS_PRINTVECTORS_H
#define PROJECTS_PRINTVECTORS_H

#endif //PROJECTS_PRINTVECTORS_H

std::string printIntVector(std::vector<int> &vectorToPrint, const std::string& separator) {
    std::string out;
    for (int &it: vectorToPrint) {
        out += std::to_string(it) + separator;
    }
    return out;
}

std::string printIntVector(std::vector<unsigned long long> &vectorToPrint, const std::string& separator) {
    std::string out;
    for (unsigned long long &it: vectorToPrint) {
        out += std::to_string(it) + separator;
    }
    return out;
}

std::string printIntVector(std::vector<unsigned long long> &vectorToPrint) {
    return printIntVector(vectorToPrint, " ");
}

std::string printIntVector(std::vector<int> &vectorToPrint) {
    return printIntVector(vectorToPrint, " ");
}

std::string printDoubleVector(std::vector<double> &vectorToPrint, const std::string& separator) {
    std::string out;
    for (double &it: vectorToPrint) {
        out += std::to_string(it) + separator;
    }
    return out;
}

std::string printDoubleVector(std::vector<double> &vectorToPrint) {
    return printDoubleVector(vectorToPrint, " ");
}

std::string printStringVector(std::vector<std::string> &vectorToPrint, const std::string& separator) {
    std::string out;
    for (std::string &it: vectorToPrint) {
        out += it + separator;
    }
    return out;
}

std::string printStringVector(std::vector<std::string> &vectorToPrint) {
    return printStringVector(vectorToPrint, " ");
}