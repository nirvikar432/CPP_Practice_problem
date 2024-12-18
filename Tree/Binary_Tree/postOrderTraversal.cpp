#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int v)
    {
        value = v;
        left = right = NULL;
    }
};

void postOrderTraversal(Node *rootNode)
{
    if (rootNode == NULL)
    {
        return;
    }
    postOrderTraversal(rootNode->left);
    postOrderTraversal(rootNode->right);
    cout << rootNode->value << " ";
}
int main()
{
    Node *rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    postOrderTraversal(rootNode);
    return 0;
}