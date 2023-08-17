#include <iostream>
using namespace std;

int numberOfOnes(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    cout << numberOfOnes(0);
    return 0;
}