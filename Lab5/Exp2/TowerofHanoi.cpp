#include <iostream>
using namespace std;
void towerOfHanoi(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n - 1, src, dest, aux);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, aux, src, dest);
}
int main()
{
    int n = 5;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}