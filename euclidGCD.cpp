#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
    int rem = 0;
    while (n1 % n2 != 0)
    {
        rem = n1 % n2;
        // cout << rem << endl;
        n1 = n2;
        n2 = rem;
        // cout << n1 << " " << n2 << " " << rem << endl;
    }
    return rem;
}

int main()
{
    cout << gcd(24, 42);
    return 0;
}