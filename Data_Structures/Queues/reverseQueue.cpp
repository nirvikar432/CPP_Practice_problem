#include <iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> qu;
    stack<int>st;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);


    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    
    return 0;
}