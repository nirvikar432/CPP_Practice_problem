#include <iostream>
using namespace std;

bool checkPowerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    else
        return (!(n & (n - 1))); // AND of N and (N-1) gives 0 if it is power of 2 and we have to handle the case for number 2
}
int main()
{
    int n;
    cout << "Enter any number to check if it is a power of two: ";
    cin >> n;
    cout << checkPowerOfTwo(n);
    return 0;
}