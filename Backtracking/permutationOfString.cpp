#include <iostream>
using namespace std;

void permutation(string &s, int i)
{
    if (i == s.size())
    {
        cout << s << endl;
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        permutation(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "abc";
    permutation(s, 0);

    return 0;
}