#include <iostream>
#include <vector>
using namespace std;

bool canWeGo(int a, int b, vector<vector<int>> &mz)
{
    return (a < mz.size() && b < mz.size() && a >= 0 && b >= 0) && mz[a][b] == 1;
}

int ratInMaze(int i, int j, vector<vector<int>> &mz)
{
    int size = mz.size();
    if (i == size - 1 && j == size - 1)
    {
        return 1;
    }

    int ans = 0;
    mz[i][j] = 2;

    if (canWeGo(i, j + 1, mz))
        ans += ratInMaze(i, j + 1, mz);
    if (canWeGo(i + 1, j, mz))
        ans += ratInMaze(i + 1, j, mz);
    if (canWeGo(i, j - 1, mz))
        ans += ratInMaze(i, j - 1, mz);
    if (canWeGo(i - 1, j, mz))
        ans += ratInMaze(i - 1, j, mz);

    mz[i][j] = 1;

    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1}};

    int res = ratInMaze(0, 0, grid);
    cout << res;
    return 0;
}