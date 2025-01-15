#include <iostream>
using namespace std;
class Rectangle
{
private:
    double length, breadth;

public:
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }
    double calculateArea() const
    {
        return length * breadth;
    }
    double calculatePerimeter() const
    {
        return 2 * (length + breadth);
    }
    void display() const
    {
        cout << "Length: " << length << ", Breadth: " << breadth
             << ", Area: " << calculateArea()
             << ", Perimeter: " << calculatePerimeter() << endl;
    }
};
int main()
{
    Rectangle rect1(4.5, 3.0);
    Rectangle rect2(6.0, 2.5);
    cout << "Rectangle 1:" << endl;
    rect1.display();

    cout << "\nRectangle 2:" << endl;
    rect2.display();
    return 0;
}
