#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
    int profit, weight;
    double ratio;
};
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}
double fractionalKnapsack(int capacity, vector<Item> &items)
{
    for (auto &item : items)
        item.ratio = (double)item.profit / item.weight;

    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (auto &item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            totalProfit += item.profit;
        }
        else
        {
            totalProfit += item.ratio * capacity;
            break;
        }
    }
    return totalProfit;
}
int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    cout << "Maximum Profit: " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
