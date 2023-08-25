// Given head, the head of a linked list, determine if the linked list is a palindrome or not.

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

Node *midValueOfLL(Node *&head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

bool isPalindromeLL(Node *&head)
{
    Node *midValue = midValueOfLL(head);
    Node *head2 = reverseLL(midValue);

    Node *head1 = head;

    while (head2)
    {
        if (head1->val != head2->val)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    linkedList ll1;
    ll1.insertAtEnd(1);
    ll1.insertAtEnd(2);
    ll1.insertAtEnd(3);
    // ll1.insertAtEnd(4);
    ll1.insertAtEnd(2);
    ll1.insertAtEnd(1);
    ll1.display();
    cout << endl
         << isPalindromeLL(ll1.head) << endl;

    return 0;
}