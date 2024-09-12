#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

bool canPlaceQueen(vector<vector<char>> &grid, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < grid.size(); i--, j++)
    {
        if (grid[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void nQueen(vector<vector<char>> &grid, int currRow, int n)
{
    if (currRow == n)

    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------------\n";
    }

    for (int col = 0; col < n; col++)
    {
        if (canPlaceQueen(grid, currRow, col))
        {
            grid[currRow][col] = 'Q';
            nQueen(grid, currRow + 1, n);
            grid[currRow][col] = '.';
        }
    }
}

int main()
{
    int n = 4;
    // cin>>n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    nQueen(grid, 0, n);

    return 0;
}