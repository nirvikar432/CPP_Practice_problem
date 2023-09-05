#include <iostream>
#include <stack>
using namespace std;

class Queue         //PUSH efficient
{
    stack<int> st;
    stack<int> temp;

public:
    Queue(){};
    void push(int val)
    {
        st.push(val);
        return;
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        while (st.size() > 1)
        {
            int var = st.top();
            st.pop();
            temp.push(var);
        }
        st.pop();
        while (!temp.empty())
        {
            int var = temp.top();
            temp.pop();
            st.push(var);
        }
        return;
    }

    int front()
    {
        if (st.empty())
            return -1;
        while (st.size() > 1)
        {
            int var = st.top();
            st.pop();
            temp.push(var);
        }
        int result = st.top();
        while (!temp.empty())
        {
            int var = temp.top();
            temp.pop();
            st.push(var);
        }
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
    cout << qu.front() << endl;
    qu.pop();
    qu.pop();

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}