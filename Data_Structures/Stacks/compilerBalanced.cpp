#include <iostream>
#include <stack>
using namespace std;

int bracketBalance(string s)
{
    stack<char> op;
    stack<int> nums;

    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(')
        {
            op.push(s[i]);
        }
        else if (isdigit(s[i]))
        {
            nums.push(s[i] - '0');
        }
    }
}

int main()
{

    return 0;
}
