// Make string equal

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool equalString(vector<string> &v)
{
    int vSize = v.size();
    unordered_map<char, int> ch;

    for (string words : v)
    {
        for (char character : words)
        {
            ch[character]++;
        }
    }

    unordered_map<char, int>::iterator itr;

    for (itr = ch.begin(); itr != ch.end(); itr++)
    {
        if (itr->second % vSize != 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << (equalString(v) ? "YES" : "NO");

    return 0;
}

/*

input case 1
3
collegeee
coll
collegge

input case 2

3
wall
ah
wallahah




*/