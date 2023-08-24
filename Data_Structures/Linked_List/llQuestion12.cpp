// Slow Fast pointer
// Find the middle element of the given linked list

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
    }

    void insertAtEnd(int val)
    {
        Node *new_node = new Node(val);

        if (head == NULL)
        {
            head = new_node;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *searchMidElem(Node *&head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

int main()
{
    linkedList ll1;
    ll1.insertAtEnd(1);
    ll1.insertAtEnd(2);
    ll1.insertAtEnd(3);
    ll1.insertAtEnd(4);
    ll1.insertAtEnd(5);
    ll1.insertAtEnd(6);
    ll1.display();
    Node *midNode = searchMidElem(ll1.head);
    cout << midNode->val;

    return 0;
}