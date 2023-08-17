#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str = "nirvikar";
    string str1 = "NIRVIKAR";

    // convert to upper case

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (str[i] >= 'a' && str[i] <= 'z')
    //     {
    //         str[i] -= 32;
    //     }
    // }
    // cout << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << str << endl;

    // convert to lower case

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str1[i] += 32;
        }
    }
    cout << str1 << endl;
    return 0;
}