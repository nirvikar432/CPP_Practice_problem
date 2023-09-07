#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool checkAllAlphabets(string s)
{
    if (s.length() < 26)
    {
        return false;
    }
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    set<char> result;
    for (auto elem : s)
    {
        result.insert(elem);
    }
    return (result.size() == 26);
}

int main()
{
    string input;
    cin >> input;

    if (checkAllAlphabets(input))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}