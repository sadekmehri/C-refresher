#ifndef LIST_IMPL_H_INCLUDED
#define LIST_IMPL_H_INCLUDED
#include <iostream>
#include <cassert>
#include <limits>
#include "List.h"

using namespace std;

const auto infinity = numeric_limits<int>::infinity();

template <class T>
List<T>::List(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
            << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else {
        maxSize = size;
    }

    length = 0;
    list = new T[maxSize];

    assert(list != nullptr);
}

template <class T>
List<T>::List(const List<T>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new T[maxSize];

    assert(list != nullptr);

    for (int j = 0; j < length; j++)
        list[j] = otherList.list[j];
}

template <class T>
const List<T>& List<T>::operator=(const List<T>& otherList)
{
    if (this != &otherList)
    {
        delete[] list;
        list = nullptr;

        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new T[maxSize];

        assert(list != nullptr);

        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }

    return *this;
}

template <class T>
bool List<T>::isEmpty() const
{
    return (length == 0);
}

template <class T>
bool List<T>::isFull() const
{
    return (length == maxSize);
}

template <class T>
int List<T>::listSize() const
{
    return length;
}

template <class T>
int List<T>::maxListSize() const
{
    return maxSize;
}


template <class T>
T List<T>::min() const
{
    if (length == 0)
    {
        cerr << "Cannot get the min item from an empty list." << endl;
        return -infinity;
    }

    T minItem = list[0];

    for (int i = 1; i < length; i++)
    {
        if (list[i] < minItem)
            minItem = list[i];
    }

    return minItem;
}

template <class T>
T List<T>::max() const
{
    if (length == 0)
    {
        cerr << "Cannot get the max item from an empty list." << endl;
        return infinity;
    }

    T maxItem = list[0];

    for (int i = 1; i < length; i++)
    {
        if (list[i] > maxItem)
            maxItem = list[i];
    }

    return maxItem;
}

template <class T>
void List<T>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class T>
bool List<T>::isItemAtEqual(int location, const T& item) const
{
    return (list[location] == item);
}

template <class T>
void List<T>::insertAt(int location, const T& insertItem)
{
    if (location < 0 || location >= maxSize)
    {
        cerr << "The position of the item to be inserted "
            << "is out of range" << endl;
        return;
    }

    if (length >= maxSize)
    {
        cerr << "Cannot insert in a full list" << endl;
        return;
    }

    for (int i = length; i > location; i--)
        list[i] = list[i - 1];

    list[location] = insertItem;
    length++;
}

template <class T>
void List<T>::insertEnd(const T& insertItem)
{
    if (length >= maxSize)
    {
        cerr << "Cannot insert in a full list" << endl;
        return;
    }

    list[length] = insertItem;
    length++;
}

template <class T>
void List<T>::retrieveAt(int location, T& retItem) const
{
    if (location < 0 || location >= length)
    {
        cerr << "The location of the item to be retrieved is "
            << "out of range." << endl;
        return;
    }

    retItem = list[location];
}

template <class T>
void List<T>::replaceAt(int location, const T& repItem)
{
    if (location < 0 || location >= length)
    {
        cerr << "The location of the item to be retrieved is "
            << "out of range." << endl;
        return;
    }

    list[location] = repItem;
}

template <class T>
void List<T>::clearList()
{
    length = 0;
}

template <class T>
int List<T>::seqSearch(const T& item) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length ; loc++)
    {
        if (list[loc] == item)
        {
            found = true;
            break;
        }
    }

    return found ? loc : -1;
}

template <class T>
void List<T>::insert(const T& insertItem)
{
    if (length == 0)
    {
        list[length++] = insertItem;
        return;
    }

    if (length == maxSize)
    {
        cerr << "Cannot insert in a full list." << endl;
        return;
    }

    int loc = seqSearch(insertItem);

    if (loc != -1)
    {
        cerr << "the item to be inserted is already in "
            << "the list. No duplicates are allowed." << endl;
        return;
    }

    list[length++] = insertItem;
}

template<class T>
void List<T>::remove(const T& removeItem)
{
    if (length == 0) {
        cerr << "Cannot delete from an empty list." << endl;
        return;
    }

    int loc = seqSearch(removeItem);

    if (loc == -1)
    {
        cout << "The item to be deleted is not in the list."
            << endl;

        return;
    }

    removeAt(loc);
}

template <class T>
void List<T>::removeAll(const T& removeItem)
{
    if (length == 0)
    {
        cerr << "Cannot delete from an empty list." << endl;
        return;
    }

    int i = 0;

    while (i < length)
    {
        if (list[i] == removeItem) {
            list[i] = list[length - 1];
            length--;
        }
        else {
            i++;
        }
    }
}

template <class T>
void List<T>::removeAt(int location)
{
    if (location < 0 || location >= length)
    {
        cerr << "The location of the item to be removed "
            << "is out of range" << endl;
        return;
    }

    for (int i = location; i < length - 1; i++)
        list[i] = list[i + 1];

    length--;
}

template <class T>
istream& operator>>(istream& is, List<T>& currList)
{
    cout << "The length of this array is: "
        << currList.length - 1 << endl;

    for (int i = 0; i < currList.length; i++)
    {
        cout << "Enter the value of T[" << i + 1 << "]: ";
        is >> currList.list[i];
    }

    return is;
}

template <class T>
List<T>::~List()
{
    delete[] list;
    list = nullptr;
}

#endif
