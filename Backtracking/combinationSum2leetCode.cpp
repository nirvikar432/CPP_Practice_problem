#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
void fun(vector<int> &candidate, int idx, int target, vector<int> &v)
{
    if (target == 0)
    {
        result.push_back(v);
        return;
    }
    if (idx == candidate.size())
        return;
    if (candidate[idx] <= target)
    {
        v.push_back(candidate[idx]);
        fun(candidate, idx + 1, target - candidate[idx], v);
        v.pop_back();
    }
    int j = idx + 1;
    while (j < candidate.size() && candidate[j] == candidate[j - 1])
        j++;
    fun(candidate, j, target, v);
}
vector<vector<int>> combinationSum(vector<int> &candidate, int target)
{
    result.clear();
    sort(candidate.begin(), candidate.end());
    vector<int> v;
    fun(candidate, 0, target, v);
    return result;
}

int main()
{
    vector<int> arr{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr, target);
    for (const auto x : ans)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}