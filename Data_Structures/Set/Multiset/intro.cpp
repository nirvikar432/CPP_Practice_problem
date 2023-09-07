#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;

    ms.insert(2);
    ms.insert(4);
    ms.insert(3);
    ms.insert(3);
    ms.insert(5);

    for (auto value : ms)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}