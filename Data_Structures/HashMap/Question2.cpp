// check for anagram

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool anagram(vector<string> &v)
{
    int vSize = v.size();
    unordered_map<char, int> ch;

    for (string words : v)
    {
        for (char character : words)
        {
            if (words == v[1])
                ch[character]++;
            else
            {
                ch[character]--;
            }
        }
    }

    unordered_map<char, int>::iterator itr;

    for (itr = ch.begin(); itr != ch.end(); itr++)
    {
        if (itr->second != 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    // int n;
    // cin >> n;

    vector<string> v(2);

    for (int i = 0; i < 2; i++)
    {
        cin >> v[i];
    }

    cout << (anagram(v) ? "Anagram" : "Not Anagram");

    return 0;
}

/*

input case 1
triangle
integral

input case 2

anagram
grams



*/