// You are given the head of a singly linked list. The list can be representes as:
// L0 -> L1 -> ... -> Ln-1 -> Ln
// Reordered the list to be on the following form:
// L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...

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

Node *middleElement(Node *&head)
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

Node *reverseLL(Node *&head)
{
    Node *prevPtr = head;
    Node *currentPtr = head->next;
    head->next = NULL;

    while (currentPtr)
    {
        Node *nextPtr = currentPtr->next;
        currentPtr->next = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }
    return prevPtr;
}

Node *altPattern(Node *&head)
{
    Node *midElem = middleElement(head);
    Node *head2 = reverseLL(midElem);
    Node *head1 = head;

    while (head1 != head2)
    {
        Node *temp = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = temp;
    }
    return head;
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

    ll1.head = altPattern(ll1.head);
    ll1.display();

    return 0;
}