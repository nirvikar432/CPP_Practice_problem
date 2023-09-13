#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) // 1 2 3 4 5 6
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) // 1 2 3 4 5 6
    {
        cout << arr[i] << " ";
    }

    return 0;
}