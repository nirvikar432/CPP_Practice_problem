#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l1 = {1, 2, 3, 4, 5};
    auto itr = l1.begin();
    // list<int>:: iterator itr;
    cout << *itr << endl;

    // auto revItr = l1.rbegin();
    // cout << *revItr << endl;
    // advance(itr, 2);
    // cout << *itr << endl;

    // Using range based loop
    // for (auto num : l1)
    // {
    //     cout << num << endl;
    // }
    return 0;
}