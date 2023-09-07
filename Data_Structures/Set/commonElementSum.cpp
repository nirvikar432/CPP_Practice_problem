#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;
    vector<int> v1(m), v2(n);
    set<int> st;

    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> v1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }

    for (int elem : v1)
    {
        st.insert(elem);
    }

    for (int elem : v2)
    {
        if (st.find(elem) != st.end())
        {
            sum += elem;
        }
    }

    cout << sum;

    return 0;
}