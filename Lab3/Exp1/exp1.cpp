#include <iostream>
using namespace std;

struct Order
{
    int orderID;
    string itemName;
    double price;
    Order *next;
};

class OrderQueue
{
private:
    Order *head;

public:
    OrderQueue() { head = nullptr; }

    void addOrder(int id, string name, double price)
    {
        Order *newOrder = new Order{id, name, price, nullptr};
        if (!head)
            head = newOrder;
        else
        {
            Order *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newOrder;
        }
    }

    void displayOrders()
    {
        Order *temp = head;
        while (temp)
        {
            cout << "Order ID: " << temp->orderID << ", Item: " << temp->itemName << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void countOrdersAndTotalValue()
    {
        int count = 0;
        double total = 0;
        Order *temp = head;
        while (temp)
        {
            count++;
            total += temp->price;
            temp = temp->next;
        }
        cout << "Total Orders: " << count << ", Total Value: $" << total << endl;
    }

    void searchOrder(int id)
    {
        Order *temp = head;
        while (temp)
        {
            if (temp->orderID == id)
            {
                cout << "Order Found: " << temp->itemName << " ($" << temp->price << ")\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Order not found.\n";
    }

    void deleteOrder(int id)
    {
        if (!head)
            return;
        if (head->orderID == id)
        {
            Order *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Order *temp = head, *prev = nullptr;
        while (temp && temp->orderID != id)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp)
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    ~OrderQueue()
    {
        while (head)
        {
            Order *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    OrderQueue orders;
    orders.addOrder(101, "Burger", 5.99);
    orders.addOrder(102, "Pizza", 8.99);
    orders.addOrder(103, "Pasta", 7.49);

    orders.displayOrders();
    orders.countOrdersAndTotalValue();
    orders.searchOrder(102);
    orders.deleteOrder(102);
    orders.displayOrders();

    return 0;
}
