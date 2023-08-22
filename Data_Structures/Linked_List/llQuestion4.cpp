// Given the head of a singly linked list, reverse the list and return the reversed list.

#include <iostream>
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

class LinkedList
{
public:
    Node *head;
    LinkedList()
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

Node *reverseNode(Node *&head)
{
    Node *prevPtr = NULL;
    Node *currentPtr = head;

    // temp->next = prevPtr;
    while (currentPtr != NULL)
    {
        Node *nextPtr = currentPtr->next;
        currentPtr->next = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
        // nextPtr = currentPtr->next;
    }

    Node *new_head = prevPtr;
    return new_head;
}

int main()
{
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtEnd(6);
    ll.display();

    ll.head = reverseNode(ll.head);
    ll.display();

    return 0;
}