#include <iostream>
#include <map>
using namespace std;

int main()
{

    // map<string, int, greater<string>> directory;
    map<string, int> directory;

    directory["Name 1"] = 123;
    directory["Name 2"] = 124;
    directory["Name 3"] = 125;
    directory["Name 4"] = 126;
    directory["Name 4"] = 1321;
    directory.insert(make_pair("Name 5", 202020)); // O(log n)

    for (auto elem : directory)
    {
        cout << "Name " << elem.first << endl
             << "Number " << elem.second << endl;
    }

    return 0;
}