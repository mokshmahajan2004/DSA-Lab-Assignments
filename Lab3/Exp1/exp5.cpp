#include <iostream>
#include <queue>
using namespace std;

class TrafficSignal
{
private:
    queue<string> vehicles;

public:
    void insertVehicles()
    {
        string vehicleList[5] = {"Car", "Bike", "Bus", "Truck", "Auto"};
        for (const string &v : vehicleList)
        {
            vehicles.push(v);
            cout << v << " arrived at the signal.\n";
        }
    }

    void displayQueue()
    {
        queue<string> temp = vehicles;
        cout << "Vehicles waiting at the signal (Front to Back):\n";
        while (!temp.empty())
        {
            cout << temp.front() << endl;
            temp.pop();
        }
    }

    void serveVehicles(int count)
    {
        for (int i = 0; i < count; i++)
        {
            if (!vehicles.empty())
            {
                cout << vehicles.front() << " has crossed the signal.\n";
                vehicles.pop();
            }
            else
            {
                cout << "No more vehicles left in the queue!\n";
                break;
            }
        }
    }
};

int main()
{
    TrafficSignal signal;

    // Step 1: Insert 5 Vehicles
    signal.insertVehicles();

    // Step 2: Display Vehicles
    signal.displayQueue();

    // Step 3: Serve 3 Vehicles
    signal.serveVehicles(3);

    // Step 4: Display remaining queue
    cout << "After serving vehicles:\n";
    signal.displayQueue();

    return 0;
}
