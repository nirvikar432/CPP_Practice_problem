#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(2);
    us.insert(4);
    us.insert(3);
    us.insert(3);
    us.insert(5);

    for (auto value : us)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}