// Pair Sum problem

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void checkPairSum(vector<int> &vt, int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < vt.size(); i++)
    {
        int reqNum = n - vt[i];
        if (map.find(reqNum) != map.end())
        {
            cout << map[reqNum] << " " << i;
            break;
        }
        else
        {
            map.insert(make_pair(vt[i], i));
            // map[vt[i]] = i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int target;
    cin >> target;

    checkPairSum(vec, target);

    return 0;
}

/*

7
1 4 5 11 13 10 2
13

5
9 10 2 3 5
15

*/