#include <iostream>

using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point(int x = 0, int y = 0):x(x),y(y){};
        Point(const Point& point) {
            cout << "Copy Constructor was called !" << endl;
            this->x = point.x;
            this->y = point.y;
        }

        Point operator = (const Point& point) {
            cout << "operator =  was called !" << endl;
            if(this != &point) {
                this->x = point.x;
                this->y = point.y;
            }
            return *this;
        }

        ~Point(){}

        friend ostream& operator<<(ostream& osObject, const Point& point);
};

ostream& operator<<(ostream& osObject, const Point& point) {
    osObject << "X = " << point.x << "; Y = " << point.y << endl;
    return osObject;
}

int main()
{
    cout << "Hello world!" << endl;
    Point p1(50,12);
    Point p2(p1); // Copy Constructor will trigger
    Point p3 = p1; // Copy Constructor will trigger
    p2 = p1; // Copy Constructor will trigger
    cout << p1 << p2 << p3;
    return 0;
}
