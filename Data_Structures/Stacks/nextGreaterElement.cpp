#include <iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            output[st.top()]= arr[i];
            st.pop();
        }
        st.push(i);
    }

    // This loop is additional if output vector is not initialized with -1
    while(!st.empty()){
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}

int main()
{
    int n;
    cout<<"Enter vector Size : ";
    cin>>n;
    vector<int> input;
    while(n--){
        int inp;
        cin>>inp;
        input.push_back(inp);
    }

    vector <int> result = nextGreaterElement(input);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}