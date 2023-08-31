#include <iostream>
#include <stack>
using namespace std;

void deleteAtBottom(stack<int> &st)
{
    stack<int> temp;
    int n = st.size();
    while (st.size() != 1)
    {

        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();

    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void recDeleteAtBottom(stack<int> &input)
{
    if (input.size()==1)
    {
        input.pop();
        return;
    }

    int curr = input.top();
    input.pop();
    recDeleteAtBottom(input);
    input.push(curr);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // deleteAtBottom(st);
    recDeleteAtBottom(st);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }

    return 0;
}