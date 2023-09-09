#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_multimap<string, int> directory;

    directory.insert(make_pair("Sameer", 123456));
    directory.insert(make_pair("Sameer", 987654));
    directory.insert(make_pair("Sanjeev", 10129));
    directory.insert(make_pair("Raju", 9999));

    unordered_multimap<string, int>::iterator itr;

    for (itr = directory.begin(); itr != directory.end(); itr++)
    {
        cout << "Name: " << itr->first << endl
             << "Number: " << itr->second << endl;
    }

    cout << directory.count("Sameer");

    return 0;
}