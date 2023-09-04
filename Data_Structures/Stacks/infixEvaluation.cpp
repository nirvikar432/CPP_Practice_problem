#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int calculate(int n1, int n2, char op)
{
    if (op == '+')
    {
        return n1 + n2;
    }
    if (op == '-')
    {
        return n1 - n2;
    }
    if (op == '/')
    {
        return n1 / n2;
    }
    if (op == '^')
    {
        return pow(n1, n2);
    }
    return n1 * n2;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

int eval(string &str)
{
    stack<int> nums;
    stack<char> opr;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            nums.push(ch - '0');
        }
        else if (ch == '(')
        {
            opr.push(ch);
        }
        else if (ch == ')')
        {
            while (!opr.empty() && opr.top() != '(')
            {
                char op = opr.top();
                opr.pop();
                int n2 = nums.top();
                nums.pop();
                int n1 = nums.top();
                nums.pop();
                nums.push(calculate(n1, n2, op));
            }
            if (!opr.empty())
            {
                opr.pop();
            }
        }
        else
        {
            while (!opr.empty() && precedence(opr.top()) > precedence(ch))
            {
                char op = opr.top();
                opr.pop();
                int n2 = nums.top();
                nums.pop();
                int n1 = nums.top();
                nums.pop();
                nums.push(calculate(n1, n2, op));
            }
            opr.push(ch);
        }
    }

    while (!opr.empty())
    {
        char op = opr.top();
        opr.pop();
        int n2 = nums.top();
        nums.pop();
        int n1 = nums.top();
        nums.pop();
        nums.push(calculate(n1, n2, op));
    }
    return nums.top();
}

int main()
{
    string str ="1+(2*(3-1))+2";
    cout<<eval(str);

    return 0;
}