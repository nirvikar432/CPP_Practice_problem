#include <iostream>
using namespace std;
int sum(int n)
{
    // int sum1;
    if (n == 0)
    {
        return 0;
    }
    else
        // sum1 = sum(n - 1);
        return n + sum(n - 1);
}
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return n * power(n, p - 1);
    }
}
int main()
{

    int n, p;
    cin >> n >> p;
    // cout << sum(n);
    cout << power(n, p);

    return 0;
}