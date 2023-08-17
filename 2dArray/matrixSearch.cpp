#include <iostream>
using namespace std;

int main()
{
    int n, m, key;
    cin >> n >> m >> key;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // cout << key;

    int r = 0;
    int c = m - 1;
    bool flag1 = false;
    while (r < n && c >= 0)
    {
        if (a[r][c] == key)
        {
            flag1 = true;
            // break;
        }
        if (a[r][c] > key)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (flag1)
    {
        cout << "Found" << endl;
    }
    else
        cout << "Not found" << endl;

    return 0;
}

// 1 2 3 4 5 6 7 8 9