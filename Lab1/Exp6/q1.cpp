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
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};
int main()
{
    Rectangle rect(5.0, 3.0);
    rect.display();
    return 0;
}
