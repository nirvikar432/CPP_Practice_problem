#include <iostream>
#include <vector>
using namespace std;

bool canWePlace(vector<vector<char>> &grid, int row, int col, char num)
{
    for (int j = 0; j < 9; j++)
    {
        if (grid[row][j] == num)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
            return false;
    }
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;

    for (int i = r; i < (r + 3); i++)
    {
        for (int j = c; j < (c + 3); j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }
    return true;
}

bool soduko(vector<vector<char>> &grid, int row, int col)
{
    if (col == 9)
        return soduko(grid, row + 1, 0);
    if (row == 9)
        return true;
    if (grid[row][col] == '.')
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canWePlace(grid, row, col, '0' + num))
            {
                grid[row][col] = '0' + num;
                bool res = soduko(grid, row, col + 1);
                if (res)
                    return true;
                grid[row][col] = '.';
            }
        }
        return false;
    }
    else
    {
        return soduko(grid, row, col + 1);
    }
}

void solveSudoku(vector<vector<char>> &grid)
{
    soduko(grid, 0, 0);
}

int main()
{

    return 0;
}

/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/