#include <iostream>
using namespace std;

void subStr(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;

        return;
    }
    char ch = s[0];
    string ros = s.substr(1);

    subStr(ros, ans);
    subStr(ros, ans + ch);
}

void subStr1(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;

        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subStr1(ros, ans);
    subStr1(ros, ans + ch);
    subStr1(ros, ans + to_string(code));
}
int main()
{
    subStr1("AB", "");

    return 0;
}