#include <iostream>
#include <stack>
using namespace std;

class Queue // POP efficient
{
    stack<int> st;
    stack<int> temp;

public:
    Queue(){};
    void push(int val)
    {
        stack<int> temp; // st 1 2 3 4            t  4 3 2 1
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        st.push(val);
        while (!temp.empty())
        {
            int x = temp.top();
            temp.pop();
            st.push(x);
        }
        return;
    }

    void pop()
    {
        if (st.empty())
            return;
        st.pop();
    }

    int front()
    {
        if (st.empty())
            return -1;
        int result = st.top();
        return result;
    }

    bool empty()
    {
        return st.empty();
    }
};
int main()
{
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    // cout << qu.front() << endl;
    qu.pop();
    // qu.pop();

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}