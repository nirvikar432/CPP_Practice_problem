#include <iostream>
#include <vector>
using namespace std;

bool canWePlaceKnight(vector<vector<char>> &grid, int row, int col)
{
    if (row - 1 >= 0 && col - 2 >= 0 && grid[row - 1][col - 2] == 'K')
        return false;
    if (row - 2 >= 0 && col - 1 >= 0 && grid[row - 2][col - 1] == 'K')
        return false;
    if (row - 1 >= 0 && col + 2 >= 0 && grid[row - 1][col + 2] == 'K')
        return false;
    if (row - 2 >= 0 && col + 1 >= 0 && grid[row - 2][col + 1] == 'K')
        return false;
    return true;
}

void knights(vector<vector<char>> &grid, int gRow, int gCol, int num, int row, int col)
{
    if (num == 0)
    {
        for (int i = 0; i < gRow; i++)
        {
            for (int j = 0; j < gCol; j++)
            {
                cout << grid[i][j];
            }
            cout << "\n";
        }
        cout << "********\n";
        return;
    }

    if (col == gCol)
    {
        return knights(grid, gRow, gCol, num, row + 1, 0);
    }
    if (row == gRow)
    {
        return;
    }
    for (int currRow = row; currRow < gRow; currRow++)
    {
        for (int currCol = col /*(currRow == row ? col : 0)*/; currCol < gCol; currCol++)
        {
            if (canWePlaceKnight(grid, currRow, currCol))
            {
                grid[currRow][currCol] = 'K';
                knights(grid, gRow, gCol, num - 1, currRow, currCol + 1);
                grid[currRow][currCol] = '_';
            }
        }
    }
}

int main()
{
    int gRow = 3, gCol = 3, num = 2;
    vector<vector<char>> grid(gRow, vector<char>(gRow, '_'));
    knights(grid, gRow, gCol, num, 0, 0);

    return 0;
}