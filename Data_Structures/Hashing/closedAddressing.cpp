#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Hashing
{
    vector<list<int>> hashtable;
    int buckets;

public:
    Hashing(int size)
    {
        buckets = size;
        hashtable.resize(size);
    }

    int hashValue(int key)
    {
        return key % buckets; // division method
    }

    void addKey(int key)
    {
        int idx = hashValue(key);
        hashtable[idx].push_back(key); // adding key at the end of the ll.
    }

    list<int>::iterator searchKey(int key)
    {
        int idx = hashValue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        if (searchKey(key) != hashtable[idx].end())
        {
            hashtable[idx].erase(searchKey(key));
            cout << key << " is deleted" << endl;
        }
        else
        {
            cout << "Key not found" << endl;
        }
    }
};
int main()
{
    // Hashing *h = new Hashing(10);
    Hashing h(10);
    // h->addKey(5);
    // h->addKey(9);
    // h->addKey(3);

    // h->deleteKey(3);

    h.addKey(5);
    h.addKey(9);
    h.addKey(3);
    // h.addKey(3);

    h.deleteKey(3);
    // h.deleteKey(3);

    return 0;
}