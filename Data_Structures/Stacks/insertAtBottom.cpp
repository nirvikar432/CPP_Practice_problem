#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> &inputStack,int val)
{
    stack<int> temp;
    while (!inputStack.empty())
    {
        int curr = inputStack.top();
        inputStack.pop();
        temp.push(curr);
    }
    inputStack.push(val);
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        inputStack.push(curr);
    }
    return inputStack;
}

void recinsertAtBottom(stack<int> &input,int val)
{
    if (input.empty())
    {
        input.push(val);
        return;
    }

    int curr = input.top();
    input.pop();
    recinsertAtBottom(input,val);
    input.push(curr);

    
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtBottom(st,20);
    // recinsertAtBottom(st,20);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }

    return 0;
}