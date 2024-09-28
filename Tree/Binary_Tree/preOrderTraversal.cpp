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

void preOrerTraversal(Node* rootNode){
    if(rootNode == NULL){
        return;
    }
    cout<<rootNode->value<<" ";
    preOrerTraversal(rootNode->left);
    preOrerTraversal(rootNode->right);
}

int main()
{
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    preOrerTraversal(rootNode);
    
    return 0;
}


// output : 2 4 6 5 10 11