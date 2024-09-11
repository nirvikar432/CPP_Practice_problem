#include <iostream>
#include <stack>
using namespace std;

void bracketBalance(string s)
{
    stack<char> op;
    stack<int> nums;

    int size = s.length();
    int oper = 0;
    int bracket = 0;
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
        else if ((s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-') && (s[i + 1] == ')'))
        {
            oper++;
        }
        else if (!op.empty() && s[i] == ')')
        {
            op.pop();
        }
    }
    cout << "Bracket :" << op.size() << "\nOperand :" << oper;
}

int main()
{
    string str = "(1+(2*(3-1+2+))+2";
    bracketBalance(str);

    return 0;
}