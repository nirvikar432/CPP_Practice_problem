// 32. Longest Valid Parentheses
//         Solved
//             Hard
//                 Topics
//                     Companies
//                         Given a string containing just the characters '(' and
//     ')',
//     return the length of the longest valid(well - formed) parentheses
//                substring
//                    .

//            Example 1 :

//     Input : s = "(()" Output : 2 Explanation : The longest valid parentheses substring is "()".Example 2 :

//     Input : s = ")()())" Output : 4 Explanation : The longest valid parentheses substring is "()()".Example 3 :

//     Input : s = "" Output : 0

//                 Constraints :

//                 0 <= s.length <= 3 * 104 s[i] is '(',
//             or ')'.

// MY solution
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    int count = 0;
    st.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                count = max(count, i - st.top());
            }
        }
    }
    return count;
}

int main()
{
    string s = ")()()(";
    int ans = longestValidParentheses(s);
    cout << ans;
}
