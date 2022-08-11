#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#include "List.h"
#define SIZE 10

using namespace std;

class Polynomial: public List<double> {
    public:
        Polynomial(int size = SIZE);
        Polynomial operator+(const Polynomial&);
        Polynomial operator-(const Polynomial&);
        Polynomial operator*(const Polynomial&);
        double operator() (double x);
        friend ostream& operator<<(ostream&, const Polynomial&);
        friend istream& operator>>(istream&, Polynomial&);
        int min(int x, int y) const;
        int max(int x, int y) const;
};

#endif // POLYNOMIAL_H_INCLUDED
