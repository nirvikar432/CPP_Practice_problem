#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    // This loop is additional if output vector is not initialized with -1
    while (!st.empty())
    {
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    // This loop is additional if output vector is not initialized with -1
    while (!st.empty())
    {
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}

vector<int> prevGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    reverse(output.begin(), output.end());
    return output;
}

vector<int> prevSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    // reverse(arr.begin(), arr.end());
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    reverse(output.begin(), output.end());
    return output;
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

    vector<int> result = nextGreaterElement(input);
    vector<int> result1 = nextSmallerElement(input);
    vector<int> result2 = prevGreaterElement(input);
    vector<int> result3 = prevSmallerElement(input);

    cout<<"nextGreaterElement"<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
    cout<<"nextSmallerElement"<<endl;
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }

    cout << endl;
    cout<<"prevGreaterElement"<<endl;
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result2[i] << " ";
    }

    cout << endl;
    cout<<"prevSmallerElement"<<endl;
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result3[i] << " ";
    }

    return 0;
}

// 10
// 4 6 3 1 0 9 5 6 7 3