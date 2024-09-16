#include <iostream>
#include <vector>

using namespace std;

// bool canWePlace(vector<vector<int>> &grid, int row, int col)
// {
//     if (row - 1 >= 0 && col - 2 >= 0 && grid[row - 1][col - 2] >= 0)
//         return false;
//     if (row - 2 >= 0 && col - 1 >= 0 && grid[row - 2][col - 1] >= 0)
//         return false;
//     if (row - 1 >= 0 && col + 2 >= 0 && grid[row - 1][col + 2] >= 0)
//         return false;
//     if (row - 2 >= 0 && col + 1 >= 0 && grid[row - 2][col + 1] >= 0)
//         return false;
//     if (row + 1 >= 0 && col - 2 >= 0 && grid[row + 1][col - 2] >= 0)
//         return false;
//     if (row + 2 >= 0 && col - 1 >= 0 && grid[row + 2][col - 1] >= 0)
//         return false;
//     if (row + 1 >= 0 && col + 2 >= 0 && grid[row + 1][col + 2] >= 0)
//         return false;
//     if (row + 2 >= 0 && col + 1 >= 0 && grid[row + 2][col + 1] >= 0)
//         return false;
//     return true;
// }

bool knightTours(vector<vector<int>> &grid, int size, int row, int col, int count)
{
    if (row < 0 || col < 0 || row >= size || col >= size || grid[row][col] >= 0)
        return false;

    if (count == size * size - 1)
    {
        grid[row][col] = count;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << grid[i][j] << '\t';
            }
            cout << "\n";
        }
        return true;
    }

    grid[row][col] = count;
    if (knightTours(grid, size, row - 1, col + 2, count + 1))
        return true;
    if (knightTours(grid, size, row + 1, col + 2, count + 1))
        return true;
    if (knightTours(grid, size, row - 1, col - 2, count + 1))
        return true;
    if (knightTours(grid, size, row + 1, col - 2, count + 1))
        return true;
    if (knightTours(grid, size, row - 2, col + 1, count + 1))
        return true;
    if (knightTours(grid, size, row - 2, col - 1, count + 1))
        return true;
    if (knightTours(grid, size, row + 2, col - 1, count + 1))
        return true;
    if (knightTours(grid, size, row + 2, col + 1, count + 1))
        return true;
    grid[row][col] = -1;
    return false;
}

int main()
{
    int size = 6;
    vector<vector<int>> grid(size, (vector<int>(size, -1)));
    knightTours(grid, size, 0, 0, 0);

    return 0;
}