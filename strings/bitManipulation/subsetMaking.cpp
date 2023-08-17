#include <iostream>
using namespace std;

void subsets(int arr[], int size)
{
    for (int i = 0; i < (1 << size); i++)
    {
        cout << "{ ";
        for (int j = 0; j < size; j++)
        {

            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << "}";
        cout << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = 4;
    subsets(arr, size);

    return 0;
}