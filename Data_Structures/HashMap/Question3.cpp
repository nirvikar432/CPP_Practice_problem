// Strings are isomorphic or not.

#include <iostream>
#include <unordered_map>
using namespace std;

bool checkOneToManyMapping(string s1, string s2)
{
    unordered_map<char, char> map;

    for (int i = 0; i < s1.length(); i++)
    {
        if (map.find(s1[i]) != map.end())
        {
            if (map[s1[i]] != s2[i])
            {
                return false;
            }
        }
        else
        {
            map[s1[i]] = s2[i];
        }
    }
    return true;
}

bool isIsomorphic(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    bool s1s2 = checkOneToManyMapping(s1, s2);
    bool s2s1 = checkOneToManyMapping(s2, s1);

    return s1s2 && s2s1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isIsomorphic(s1, s2) ? "Is Isomorphic" : "Is not Isomorphic");

    return 0;
}

/*

aab
xxy


abcdec
viouog

abcdem
viouog

*/