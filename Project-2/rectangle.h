#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

using namespace std;

class Rectangle {
    private:
        double length;
        double width;
    public:
        Rectangle();
        Rectangle(double, double);
        void setDimension(double, double);
        double getLength() const;
        double getWidth() const;
        double perimeter() const;
        double area() const;
        void print() const;

        Rectangle operator + (const Rectangle&) const;
        Rectangle operator - (const Rectangle&) const;
        Rectangle operator * (const Rectangle&) const;

        Rectangle operator ++ ();
        Rectangle operator ++ (int);
        Rectangle operator -- ();
        Rectangle operator -- (int);

        bool operator == (const Rectangle&) const;
        bool operator != (const Rectangle&) const;
        bool operator <= (const Rectangle&) const;
        bool operator < (const Rectangle&) const;
        bool operator >= (const Rectangle&) const;
        bool operator > (const Rectangle&) const;

        friend ostream& operator<<(ostream& osObject, const Rectangle& rectangle);
        friend istream& operator>>(istream& isObject, Rectangle& rectangle);

        ~Rectangle();
};


#endif // RECTANGLE_H_INCLUDED
