#include <iostream>
#include <stack>
#include <vector>
#define ll long long int

using namespace std;

class MinStack
{
public:
    stack<ll> st;
    ll mn;
    MinStack()
    {
        this->mn = INT_MAX;
    }

    void push(int val)
    {
        if (this->st.empty())
        {
            this->st.push(val);
            this->mn = val;
        }
        else
        {
            this->st.push(val - this->mn);
            if (this->mn > val)
            {
                this->mn = val;
            }
        }
    }

    void pop()
    {
        if (!this->st.empty())
        {
            if (this->st.top() >= 0)
            {
                st.pop();
            }
            else
            {
                this->mn = this->mn - this->st.top();
                this->st.pop();
            }
        }
    }

    int top()
    {
        if (this->st.size() == 1)
            return this->st.top();
        else if (this->st.top() < 0)
        {
            return this->mn;
        }
        else
        {
            return this->mn + this->st.top();
        }
    }

    int getMin()
    {
        return this->mn;
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;

    return 0;
}