#ifndef RECTANGLE_IMPL_H_INCLUDED
#define RECTANGLE_IMPL_H_INCLUDED
#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(){
    length = 0;
    width = 0;
}

Rectangle::Rectangle(double length, double width) {
    setDimension(length, width);
}

void Rectangle::setDimension(double length, double width) {
    this->length = length >= 0 ? length : 0;
    this->width = width >= 0 ? width : 0;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth()const {
    return width;
}

double Rectangle::area() const {
    return length * width;
}

double Rectangle::perimeter() const {
    return 2 * (length + width);
}

Rectangle Rectangle::operator++() {
    ++length;
    ++width;

    return *this;
}

Rectangle Rectangle::operator++(int) {
    Rectangle rectangleTemp = *this;

    length++;
    width++;

    return rectangleTemp;
}

Rectangle Rectangle::operator--() {
    bool isValidDimention = length >= 0 && width >= 0;

    if(isValidDimention){
        --length;
        --width;
    }

    return *this;
}

Rectangle Rectangle::operator--(int) {
    Rectangle rectangleTemp = *this;
    bool isValidDimention = length >= 0 && width >= 0;

    if(isValidDimention){
        length--;
        width--;
    }

    return rectangleTemp;
}

Rectangle Rectangle::operator+(const Rectangle& rectangle) const {
    Rectangle tempRect;
    tempRect.length = length + rectangle.length;
    tempRect.width = width + rectangle.width;

    return tempRect;
}

Rectangle Rectangle::operator-(const Rectangle& rectangle) const {
    bool isValidSubtraction = length >= rectangle.length && width >= rectangle.width;
    if(!isValidSubtraction) return *this;

    Rectangle tempRect;
    tempRect.length = length - rectangle.length;
    tempRect.width = width - rectangle.width;

    return tempRect;
}

Rectangle Rectangle::operator*(const Rectangle& rectangle) const {
    Rectangle tempRect;
    tempRect.length = length * rectangle.length;
    tempRect.width = width * rectangle.width;

    return tempRect;
}

bool Rectangle::operator==(const Rectangle& rectangle) const {
    return area() == rectangle.area();
}

bool Rectangle::operator!=(const Rectangle& rectangle) const {
    return area() != rectangle.area();
}

bool Rectangle::operator<=(const Rectangle& rectangle) const {
    return area() <= rectangle.area();
}

bool Rectangle::operator<(const Rectangle& rectangle) const {
    return area() < rectangle.area();
}

bool Rectangle::operator>=(const Rectangle& rectangle) const {
    return area() >= rectangle.area();
}

bool Rectangle::operator>(const Rectangle& rectangle) const {
    return area() > rectangle.area();
}

ostream& operator<<(ostream& osObject, const Rectangle& rectangle) {
    osObject << "Length = " << rectangle.length << "; Width = " << rectangle.width;
    return osObject;
}

istream& operator>>(istream& isObject, Rectangle& rectangle) {
    isObject >> rectangle.length >> rectangle.width;
    return isObject;
}

Rectangle::~Rectangle(){}

#endif // RECTANGLE_IMPL_H_INCLUDED
