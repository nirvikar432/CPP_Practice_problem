// Longest sub array equal to 0

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestSubArray(vector<int> v)
{
    unordered_map<int, int> map;
}
int main()
{
    int n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    vector<int> ans(2);

    ans = longestSubArray(v);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}