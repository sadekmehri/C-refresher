#include <iostream>
#include "polynomial_impl.h"

using namespace std;

int main()
{
    Polynomial p(8);
    Polynomial q(4);
    Polynomial t;

    cin >> p;
    cout << endl << p << endl;

    cin >> q;
    cout << endl << q << endl;

    t = p + q;
    cout << "p(x) + q(x): " << endl << t << endl;

    t = p - q;
    cout << "p(x) - q(x): " << endl << t << endl;

    cout << "t(0):" << t(0) << endl;
    cout << "t(1):" << t(1) << endl;
    cout << "t(2):" << t(2) << endl;

    return 0;
}
