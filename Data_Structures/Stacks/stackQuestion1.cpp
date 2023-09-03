//Find the minimum number of brackets that need to be remove to make the given bracke sequence balanced..

#include<iostream>
#include<stack>
using namespace std;

int isBalanced(string str){
    stack<char> st;
    int count = 0;

    for(int i=0;i<str.size();i++){
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(ch =='}' && !st.empty() && st.top() == '{'){
                st.pop();
            }
            else if(ch ==']' && !st.empty() && st.top() == '['){
                st.pop();
            }
            else if(ch ==')' && !st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                count++;
            }
        }
    }
    return count;

}

int main(){
    // string str ="}({[]})[][]{}(){[]}}";
    string str ="({[]})[][]{}(){[]}";
    cout<<isBalanced(str)<<endl;

    return 0;
}