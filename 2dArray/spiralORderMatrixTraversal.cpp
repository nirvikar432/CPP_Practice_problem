#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;
    int count = n * m;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        if (count != 0)
        {
            for (int col = colStart; col <= colEnd; col++)
            {
                cout << a[rowStart][col] << " ";
                count--;
            }
            rowStart++;
        }
        if (count != 0)
        {
            for (int row = rowStart; row <= rowEnd; row++)
            {
                cout << a[row][colEnd] << " ";
                count--;
            }
            colEnd--;
        }
        if (count != 0)
        {
            for (int col = colEnd; col >= colStart; col--)
            {
                cout << a[rowEnd][col] << " ";
                count--;
            }
            rowEnd--;
        }
        if (count != 0)
        {
            for (int row = rowEnd; row >= rowStart; row--)
            {
                cout << a[row][colStart] << " ";
                count--;
            }
            colStart++;
        }
    }
    return 0;
}