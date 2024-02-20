//
// Created by daniel on 2/11/24.
//
#include "vector"
#include "string"
#include "tuple"

#ifndef PROJECTS_PRINTCOLLECTIONS_H
#define PROJECTS_PRINTCOLLECTIONS_H

#endif //PROJECTS_PRINTCOLLECTIONS_H

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

template <class T>
std::string printTuple(std::tuple<T, T> tupleToPrint, const std::string &separator){
    std::string out;
    out += std::to_string(std::get<0>(tupleToPrint)) + separator;
    out += std::to_string(std::get<1>(tupleToPrint));
    return out;
}

template <class T> std::string printTuple(std::tuple<T, T> tupleToPrint){
    return printTuple(tupleToPrint, "");
}

template <class T>
std::string printTuple(std::tuple<T, T, T> tupleToPrint, const std::string &separator){
    std::string out;
    out += std::to_string(std::get<0>(tupleToPrint)) + separator;
    out += std::to_string(std::get<1>(tupleToPrint)) + separator;
    out += std::to_string(std::get<2>(tupleToPrint));
    return out;
}

template <class T>
std::string printTuple(std::tuple<T, T, T, T> tupleToPrint, const std::string &separator){
    std::string out;
    out += std::to_string(std::get<0>(tupleToPrint)) + separator;
    out += std::to_string(std::get<1>(tupleToPrint)) + separator;
    out += std::to_string(std::get<2>(tupleToPrint)) + separator;
    out += std::to_string(std::get<3>(tupleToPrint));
    return out;
}