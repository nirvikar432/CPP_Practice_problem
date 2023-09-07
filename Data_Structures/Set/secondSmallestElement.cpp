#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<int> s;
    for (auto value : v)
    {
        s.insert(value);
    }
    set<int>::iterator itr = s.begin();
    itr++;
    cout << *itr << endl;

    return 0;
}