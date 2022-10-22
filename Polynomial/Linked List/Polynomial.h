//
// Created by vivek on 22-10-2022.
//

#ifndef LINKED_LIST_POLYNOMIAL_H
#define LINKED_LIST_POLYNOMIAL_H

#include <ostream>

struct Term {
    unsigned int exponent;
    int coefficient;
    Term *next;

    Term(unsigned int exponent, int coefficient) : exponent(exponent), coefficient(coefficient) {
        next = nullptr;
    }
};


class Polynomial {
    Term *poly;
public:
    explicit Polynomial(unsigned int exponent, int coefficient) {
        poly = new Term(exponent, coefficient);
    }

    explicit Polynomial(Term *poly) : poly(poly){}

    void add_term(unsigned int exponent, int coefficient);

    int eval(int x);

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
        Term *p = polynomial.poly;
        while (p) {
            os << p->coefficient << "x^" << p->exponent;
            if (p->next != nullptr)
                os << " + ";
            p = p->next;
        } return os;
    }

    virtual ~Polynomial();
};


#endif //LINKED_LIST_POLYNOMIAL_H