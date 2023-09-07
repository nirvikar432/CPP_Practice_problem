#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int> ums;

    ums.insert(2);
    ums.insert(4);
    ums.insert(3);
    ums.insert(3);
    ums.insert(5);

    for (auto value : ums)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}