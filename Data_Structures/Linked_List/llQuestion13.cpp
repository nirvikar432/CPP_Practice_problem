// Given head, the head of a linked list, determine if the linked list has a cycle in it.

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

bool detectCycleLL(Node *&head)
{
    if (!head)
    {
        return false;
    }
    Node *slowPtr = head;
    Node *fastPtr = head;

    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            cout << slowPtr->val << endl;
            return true;
        }
    }
    return false;
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
    ll1.head->next->next->next->next->next->next = ll1.head->next->next; // for cycle
    cout << detectCycleLL(ll1.head);

    return 0;
}