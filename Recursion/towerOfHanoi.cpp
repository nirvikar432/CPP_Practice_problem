#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        towerOfHanoi(n - 1, src, dest, helper);
        cout << "Moved from " << src << " to " << dest << endl;
        towerOfHanoi(n - 1, helper, src, dest);
    }
}
int main()
{
    towerOfHanoi(3, 'A', 'B', 'C');

    return 0;
}