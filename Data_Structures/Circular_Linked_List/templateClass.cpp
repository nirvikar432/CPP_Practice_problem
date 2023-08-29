#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T val;
    Node *next;
    Node(T data)
    {
        val = data;
        next = NULL;
    }
};
int main()
{

    Node<int> *node1 = new Node<int>(3);
    cout << node1->val << endl;

    Node<char> *node3 = new Node<char>('a');
    cout << node3->val << endl;

    return 0;
}