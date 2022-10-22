//
// Created by vivek on 22-10-2022.
//

#include "Polynomial.h"
#include <cmath>
#include <iostream>

int Polynomial::eval(int x) {
    int sum{0};
    for (int i{0}; i < this->length; i++)
        sum += (this->list.at(i).coefficient * pow(x, this->list.at(i).exponent));
    return sum;
}

void Polynomial::set() {
    for (int i{0}; i < this->length; i++) {
        std::cout << "Enter coefficient and exponent for term #" << (i + 1) << ": ";
        std::cin >> this->list.at(i).coefficient >> this->list.at(i).exponent;
    }
}

Polynomial Polynomial::add(Polynomial src) {
    int i{0}, j{0}, k{0};
    Polynomial result(this->length + src.length);

    while (i < this->length && j < src.length) {
        if (this->list.at(i).exponent > src.list.at(j).exponent) {
            result.list.at(k) = this->list.at(i);
            k++;
            i++;
        } else if (this->list.at(i).exponent < src.list.at(j).exponent) {
            result.list.at(k) = src.list.at(j);
            k++;
            j++;
        } else {
            result.list.at(k).exponent = this->list.at(i).exponent;
            result.list.at(k).coefficient = this->list.at(i).coefficient + src.list.at(j).coefficient;
            i++;
            j++;
            k++;
        }
    }

    for (; i < this->length; i++) {
        result.list.at(k) = this->list.at(i);
        k++;
    }
    for (; j < src.length; j++) {
        result.list.at(k) = src.list.at(j);
        k++;
    }
    result.length = k;
    return result;
}

Polynomial::~Polynomial() {
    list.clear();
}
