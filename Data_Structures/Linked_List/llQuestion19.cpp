// Given a Linked list, swap every two adjacent nodes and return its head.
// You may not modify the values in the list's nodes only nodes themselves may be changed.

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
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

Node *swapTwoAtTime(Node *&head)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    int count = 0;

    while (currPtr && count < 2)
    {
        Node *next = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = next;
        count++;
    }
    if (currPtr)
    {
        Node *newHead = swapTwoAtTime(currPtr);
        head->next = newHead;
    }

    return prevPtr;
}

Node *swapTwoAtTime1(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *secondNode = head->next;
    head->next = swapTwoAtTime1(secondNode->next);
    secondNode->next = head;
    return secondNode;
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
    // ll1.insertAtEnd(7);
    ll1.display();
    cout << endl;

    // ll1.head = swapTwoAtTime(ll1.head);
    ll1.head = swapTwoAtTime1(ll1.head);
    ll1.display();
    return 0;
}