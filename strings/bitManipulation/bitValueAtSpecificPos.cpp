#include <iostream>
#include <vector>
using namespace std;

int getBit(int num, int pos)
{
    return ((num & (1 << pos)) != 0);
}

int setBit(int num, int pos)
{
    return ((num | (1 << pos)));
}

int clearBit(int num, int pos)
{
    return ((num & ~(1 << pos)));
}

int updateBit(int num, int pos, int newVal) // First clear the bit at that position then do the OR operation with the clearbit and newvalue<<pos
{
    num = clearBit(num, pos);
    return ((num | (newVal << pos)));
}

int main()
{

    cout << "GET BIT " << getBit(5, 2) << endl;

    cout << "SET BIT " << setBit(5, 1) << endl;

    cout << "CLEAR BIT " << clearBit(5, 2) << endl;

    cout << "UPDATE BIT " << updateBit(5, 1, 1) << endl;

    return 0;
}