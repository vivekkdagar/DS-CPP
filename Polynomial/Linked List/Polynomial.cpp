//
// Created by vivek on 22-10-2022.
//

#include "Polynomial.h"
#include <cmath>

void Polynomial::add_term(unsigned int exponent, int coefficient) {
    if (poly == nullptr) {
        poly = new Term(exponent, coefficient);
    } else {
        Term *head = new Term(exponent, coefficient);
        head->next = poly;
        poly = head;
    }
}

int Polynomial::eval(int x) {
    int sum{0};
    Term *temp = this->poly;
    while (temp) {
        sum += (temp->coefficient * pow(x, temp->exponent));
        temp = temp->next;
    }
    return sum;
}


Polynomial::~Polynomial() {
    Term *temp = this->poly;
    while (temp) {
        this->poly = poly->next;
        delete temp;
        temp = this->poly;
    }
}

