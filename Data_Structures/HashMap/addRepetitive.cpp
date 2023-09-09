#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<int, int> inputMap;

    for (int i = 0; i < n; i++)
    {
        inputMap[v[i]]++;
    }

    int sum = 0;

    for (auto elem : inputMap)
    {
        if (elem.second > 1)
        {
            sum += elem.first;
        }
    }

    cout << "Ans- " << sum << endl;

    return 0;
}

// Input Case 1
// 7
// 1 1 2 1 3 3 3