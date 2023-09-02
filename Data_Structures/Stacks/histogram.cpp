#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int histogram(vector<int> &arr)
{
    int size = arr.size();
    int ans = INT_MIN;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < size; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int element = arr[st.top()];
            int nse = i;
            st.pop();
            int pse = (st.empty()) ? (-1) : st.top();
            // cout<<element<<" "<<pse<<" "<<nse<<endl;
            ans = max(ans, element * (nse - pse - 1));
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int element = arr[st.top()];
        int nse = size;
        st.pop();
        int pse = (st.empty()) ? (-1) : st.top();
        // cout<<element<<" "<<pse<<" "<<nse<<endl;
        ans = max(ans, element * (nse - pse - 1));
    }

    return ans;
}
int main()
{
    int n;
    cout << "Enter vector Size : ";
    cin >> n;
    vector<int> input;
    while (n--)
    {
        int inp;
        cin >> inp;
        input.push_back(inp);
    }

    int ans = histogram(input);
    cout<<ans<<endl;

    return 0;
}

// 13
// 2 1 5 6 2 3 0 2 1 5 6 2 3