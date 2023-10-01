// Longest sub array equal to 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int longestSubArray(vector<int> &v)
{
    unordered_map<int, int> map;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < v.size(); i++)
    {
        prefixSum += v[i];
        if (prefixSum == 0)
        {
            maxLen++;
        }
        if (map.find(prefixSum) != map.end())
        {
            maxLen = max(maxLen, i - map[prefixSum]);
        }
        else
        {
            map[prefixSum] = i;
        }
    }

    return maxLen;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << longestSubArray(v);
    return 0;
}

// 8
// 15 -2 2 -8 1 7 10 23
// 5
