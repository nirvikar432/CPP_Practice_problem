#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &inputStack)
{
    stack<int> temp;
    while (!inputStack.empty())
    {
        int curr = inputStack.top();
        inputStack.pop();
        temp.push(curr);
    }
    stack<int> result;
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void recCopyStack(stack<int> &input, stack<int> &res)
{
    if (input.empty())
    {
        return;
    }

    int curr = input.top();
    input.pop();
    recCopyStack(input, res);
    res.push(curr);

    return;
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // stack<int> resStack = copyStack(st);

    // while (!resStack.empty())
    // {
    //     int curr = resStack.top();
    //     resStack.pop();
    //     cout<<curr<<endl;
    // }
    stack<int> resStack1;
    recCopyStack(st, resStack1);

    while (!resStack1.empty())
    {
        int curr = resStack1.top();
        resStack1.pop();
        cout << curr << endl;
    }

    return 0;
}