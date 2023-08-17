#include <iostream>
using namespace std;

int getBit(int num, int pos)
{
    return ((num & (1 << pos)) != 0);
}

// int uniqueNumber(int arr[], int n)
// {
//     int xorSum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         xorSum = xorSum ^ arr[i];
//     }
//     return xorSum;
// }

void twouniqueNumber(int arr[], int n)
{
    int xorSum = 0; // XOR SUM
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];
    }

    int tempXor = xorSum;
    int getBit1 = 0;
    int pos = 0;
    while (getBit1 != 1) // POSITION OG SETBIT AT RIGHTMOST SIDE
    {
        pos++;

        getBit1 = xorSum & 1;

        xorSum = xorSum >> 1;
    }

    pos = pos - 1;
    int newXor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos)) // IF POSITION OF GETBIT IS 1 THEN DO
        {
            newXor = newXor ^ arr[i];
        }
    }
    cout << newXor << endl;
    cout << (tempXor ^ newXor) << endl;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 1, 2, 3};
    // cout << uniqueNumber(arr, 7);
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
    twouniqueNumber(arr, 8);

    return 0;
}