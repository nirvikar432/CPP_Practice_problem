#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string str;
    // // cin >> str;
    // getline(cin, str);
    // cout << str;

    string s1 = "abc";
    string s2 = "def";
    // string abc = "afadasdsdsafdafdafdafdsafdsafdsaf ddsvdsv";

    // s1.append(s2);
    // cout << s1 + s2 << endl;
    // cout << s1[0];
    // abc.clear();
    // cout << abc;\

    cout << s1.compare(s2); // s1 is smaller
    cout << s2.compare(s1); // s2 is bigger
    cout << s2.compare(s2); // equal

    return 0;
}