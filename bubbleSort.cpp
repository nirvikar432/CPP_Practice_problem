#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) // 9 6 5 4 7 2 3
    {
        cin >> arr[i];
    }

    // int counter = 1;
    for (int j = 1; j < n; j++) // no for itteration will be one less than the number of element
    {
        for (int i = 0; i < n - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) // 1 2 3 4 5 6
    {
        cout << arr[i] << " ";
    }

    return 0;
}