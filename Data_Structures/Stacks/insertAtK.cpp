#include<iostream>
#include<stack>
using namespace std;

void insertAtK(stack<int> &st, int val,int pos){
    int n = st.size();
    stack<int> temp;
    int count =0;
    while (count<n-pos)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    st.push(val);

    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtK(st,20,1);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}