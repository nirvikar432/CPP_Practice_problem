#include <iostream>
using namespace std;

void perString(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            string ros = s.substr(0, i) + s.substr(i + 1);
            perString(ros, ans + ch);
        }
    }
}
int main()
{
    perString("ABC", "");

    return 0;
}