#include <iostream>
#include <stack>
using namespace std;

void recinsertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }

    int curr = st.top();
    st.pop();
    recinsertAtBottom(st, val);
    st.push(curr);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int curr = st.top();
    st.pop();
    reverseStack(st);
    recinsertAtBottom(st, curr);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }

    return 0;
}