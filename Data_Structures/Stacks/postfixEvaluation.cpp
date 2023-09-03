#include <iostream>
#include<stack>
#include<math.h>
using namespace std;

int calculate(int n1,int n2, char op){
    if(op == '+'){
        return n1 + n2;
    }
    if(op == '-'){
        return n1 - n2;
    }
    if(op == '/'){
        return n1 / n2;
    }
    if(op == '^'){
        return pow(n1, n2);
    }
    return n1* n2;
}

int eval(string &str){
    stack<int> st;
    for(int i= 0;i<str.size();i++){
        char ch = str[i];
        if(isdigit(ch)){
            st.push(ch - '0');
        }
        else{
            int n2 = st.top();
            st.pop();
            int n1 = st.top();
            st.pop();

            st.push(calculate(n1,n2,ch));
        }
    }
    return st.top();
}
int main()
{
    string str ="231*+9-";
    cout<<eval(str);
    
    return 0;
}