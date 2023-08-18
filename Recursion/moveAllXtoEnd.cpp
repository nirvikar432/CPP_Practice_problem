#include <iostream>
using namespace std;

string pushX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    else
    {
        char ch = s[0];
        string ans = pushX(s.substr(1));
        if (ch == 'x')
        {
            return (ans + ch);
        }
        else
        {
            return ch + ans;
        }
    }
}
int main()
{
    cout << pushX("xaxbxhxystrx");

    return 0;
}