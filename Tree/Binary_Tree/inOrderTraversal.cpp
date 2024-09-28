#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* left; 
        Node* right;
        Node(int v){
            value = v;
            left = right = NULL;
        }
};

void inOrerTraversal(Node* rootNode){
    if(rootNode == NULL){
        return;
    }
    inOrerTraversal(rootNode->left);
    cout<<rootNode->value<<" ";
    inOrerTraversal(rootNode->right);
}

int main()
{
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    inOrerTraversal(rootNode);
    
    return 0;
}


// output : 6 4 5 2 10 11