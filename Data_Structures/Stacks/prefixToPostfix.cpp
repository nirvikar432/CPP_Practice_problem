#include <iostream>
#include<stack>
using namespace std;

string prefixToPostfix(string &str){
    stack<string> st;
    reverse(str.begin(),str.end());
    string ans; 
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(isdigit(ch)){
            st.push(to_string(ch -'0'));
        }
        else{  
            
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            ans = a + b + ch;
            st.push(ans);
        }
    }
    return st.top();

}
int main()
{
    string st = "*+32-15";
    cout<<prefixToPostfix(st);
    
    return 0;
}