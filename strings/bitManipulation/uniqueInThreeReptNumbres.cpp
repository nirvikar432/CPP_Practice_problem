#include <iostream>
using namespace std;
bool getBit(int num, int pos)
{
    return (num & (1 << pos) != 0);
}

int setBit(int num, int pos)
{
    return (num | (1 << pos));
}

void uniqueInThree(int arr[], int size)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setBit(result, i);
        }
    }
    cout << result;
}
int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3, 4};
    uniqueInThree(arr, 7);

    return 0;
}