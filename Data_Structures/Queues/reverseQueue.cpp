#include <iostream>
#include<stack>
#include<queue>
using namespace std;


queue<int> reverseQueue(queue<int> &qu){
    stack<int> st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }

    return qu;

}
int main()
{
    queue<int> qu;
    stack<int>st;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);


    // while(!qu.empty()){
    //     st.push(qu.front());
    //     qu.pop();
    // }

    // while(!st.empty()){
    //     qu.push(st.top());
    //     st.pop();
    // }

    queue<int> ans = reverseQueue(qu);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    
    return 0;
}