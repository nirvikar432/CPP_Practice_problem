#include<iostream>
#include<stack>
using namespace std;

void deleteAtK(stack<int> &st,int pos){
    int n = st.size();
    stack<int> temp;
    int count =0;
    while (count<n-pos-1)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    st.pop();

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
    deleteAtK(st,1);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}