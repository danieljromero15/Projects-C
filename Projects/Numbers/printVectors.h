//
// Created by daniel on 2/11/24.
//
#include <cstdlib>
#include "vector"
#include "string"

#ifndef PROJECTS_PRINTVECTORS_H
#define PROJECTS_PRINTVECTORS_H

#endif //PROJECTS_PRINTVECTORS_H

template <class T>
std::string printVector(std::vector<T> &vectorToPrint, const std::string &separator){
    std::string out;
    for(T &it: vectorToPrint){
        out += std::to_string(it) + separator;
    }
    return out;
}

template<class T> std::string printVector(std::vector<T> &vectorToPrint){
    return printVector<T>(vectorToPrint, "");
}

template<> std::string printVector<char>(std::vector<char> &vectorToPrint, const std::string &separator) {
    std::string out;
    for (char &it: vectorToPrint) {
        out += it + separator;
    }
    return out;
}

template<> std::string printVector<char>(std::vector<char> &vectorToPrint){
    return printVector<char>(vectorToPrint, "");
}

template<> std::string printVector<std::string>(std::vector<std::string> &vectorToPrint, const std::string &separator){
    std::string out;
    for(std::string &it: vectorToPrint){
        out += it + separator;
    }
    return out;
}

template<> std::string printVector<std::string>(std::vector<std::string> &vectorToPrint){
    return printVector<std::string>(vectorToPrint, "");
}