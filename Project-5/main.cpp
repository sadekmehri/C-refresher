#include <iostream>
#include "list_impl.h"

using namespace std;

int main()
{
    List<int> intList(10);
    int maxListSize = intList.maxListSize();
    int number = 0;

    cout << "The length of this array is : "
        << maxListSize << endl;

    for (int i = 0; i < maxListSize; i++)
    {
        cout << "Enter the value of T[" << i + 1 << "]: ";
        cin >> number;
        intList.insertAt(i, number);
    }

    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    cout << "Enter the item to be deleted: ";
    cin >> number;

    intList.removeAll(number);
    cout << "After removing " << number
        << ", the list is:" << endl;
    intList.print();

    cout << endl;

    return 0;
}
