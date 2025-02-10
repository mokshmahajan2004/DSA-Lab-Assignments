#include <iostream>
#include <stack>
using namespace std;

class CafeteriaStack
{
private:
    stack<int> plates;
    int plateID = 1; // Simulating plate numbering

public:
    void pushPlates(int count)
    {
        for (int i = 0; i < count; i++)
        {
            plates.push(plateID++);
            cout << "Plate " << plateID - 1 << " added to the stack.\n";
        }
    }

    void displayStack()
    {
        stack<int> temp = plates;
        cout << "Current stack of plates (Top to Bottom):\n";
        while (!temp.empty())
        {
            cout << "Plate " << temp.top() << endl;
            temp.pop();
        }
    }

    void popPlates(int count)
    {
        for (int i = 0; i < count; i++)
        {
            if (!plates.empty())
            {
                cout << "Plate " << plates.top() << " used and removed.\n";
                plates.pop();
            }
            else
            {
                cout << "No more plates left!\n";
                break;
            }
        }
    }
};

int main()
{
    CafeteriaStack cafeteria;

    // Step 1: Push 5 plates
    cafeteria.pushPlates(5);

    // Step 2: Display Stack
    cafeteria.displayStack();

    // Step 3: Pop 3 plates
    cafeteria.popPlates(3);

    // Step 4: Display remaining stack
    cout << "After removing plates:\n";
    cafeteria.displayStack();

    return 0;
}
