#ifndef POLYNOMIAL_IMPL_H_INCLUDED
#define POLYNOMIAL_IMPL_H_INCLUDED
#include <math.h>
#include "Polynomial.h"
#include "list_impl.h"

Polynomial::Polynomial(int size): List<double>(size)
{
    length = size;

    for (int i = 0; i < size; i++)
        list[i] = 0;
}

double Polynomial::operator() (double x)
{
    double value = 0.0;
    for (int i = 0; i < length; i++)
        if (list[i] != 0.0)
            value = value + list[i] * pow(x,i);

    return value;
}

int Polynomial::min(int x, int y) const
{
    return (x <= y) ? x : y;
}

int Polynomial::max(int x, int y) const
{
    return (x >= y) ? x : y;
}

Polynomial Polynomial::operator+(const Polynomial& right)
{
    int size = max(length, right.length);
    Polynomial temp(size);

    for (int i = 0; i < min(length, right.length); i++)
        temp.list[i] = list[i] + right.list[i];

    if (size == length)
        for (int i = min(length, right.length); i < length; i++)
            temp.list[i] = list[i];
    else
        for (int i = min(length, right.length); i < right.length; i++)
            temp.list[i] = right.list[i];

    return temp;
}


Polynomial Polynomial::operator-(const Polynomial& right)
{
    int size = max(length, right.length);
    Polynomial temp(size);

    for (int i = 0; i < min(length, right.length); i++)
        temp.list[i] = list[i] - right.list[i];

    if (size == length)
        for (int i = min(length, right.length); i < length; i++)
            temp.list[i] = list[i];
    else
        for (int i = min(length, right.length); i < right.length; i++)
            temp.list[i] = -right.list[i];

    return temp;
}

ostream& operator<<(ostream& os, const Polynomial& p)
{
    int indexFirstNonzeroCoeff = 0;

    for (int i = 0; i < p.length; i++)
    {
        if (p.list[i] != 0.0)
        {
            indexFirstNonzeroCoeff = i;
            break;
        }
    }

    if (indexFirstNonzeroCoeff < p.length)
    {
        if (indexFirstNonzeroCoeff == 0)
            os << p.list[indexFirstNonzeroCoeff] << " ";
        else
            os << p.list[indexFirstNonzeroCoeff] << "x^"
            << indexFirstNonzeroCoeff << " ";

        for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++)
        {
            if (p.list[i] != 0.0)
            {
                if (p.list[i] >= 0.0)
                    os << "+ " << p.list[i] << "x^" << i << " ";
                else
                    os << "- " << -p.list[i] << "x^" << i << " ";
            }
        }
    }
    else
        os << "0";

    return os;
}


istream& operator>>(istream& is, Polynomial& p)
{
    cout << "The degree of this polynomial is: "
    << p.length - 1 << endl;

    for (int i = 0; i < p.length; i++)
    {
        cout << "Enter the coefficient of x^" << i << ": ";
        is >> p.list[i];
    }

    return is;
}

#endif // POLYNOMIAL_IMPL_H_INCLUDED
