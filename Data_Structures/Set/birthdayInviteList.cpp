#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<string> inviteList;

    int n;
    cin >> n;
    while (n--)
    {
        string name;
        cin >> name;

        inviteList.insert(name);
    }

    set<string>::iterator itr;

    for (itr = inviteList.begin(); itr != inviteList.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}