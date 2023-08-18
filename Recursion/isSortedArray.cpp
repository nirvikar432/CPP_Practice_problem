#include <iostream>
using namespace std;

bool isSorted(int a[], int n)
{
    if (n == 1)
        return true;
    else
    {
        return (a[0] < a[1] && isSorted(a + 1, (n - 1)));
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, n);

    return 0;
}