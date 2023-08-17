#include <iostream>
using namespace std;

int div(int n, int a, int b)
{
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / (a * b);

    return (c1 + c2 - c3);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << div(a, b, c);

    return 0;
}