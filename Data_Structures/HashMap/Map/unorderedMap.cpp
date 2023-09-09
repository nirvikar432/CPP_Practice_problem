#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> record;

    record.insert(make_pair(1, "Sameer"));
    record.insert(make_pair(3, "Ishaan"));
    record.insert(make_pair(7, "Sanjeev"));
    record.insert(make_pair(2, "Piyush"));

    unordered_map<int, string>::iterator itr;

    for (itr = record.begin(); itr != record.end(); itr++)
    {
        cout << "Roll: " << itr->first << endl
             << "Name: " << itr->second << endl;
    }

    return 0;
}