// Given head, the head of a linked list, determine if the linked list has a cycle in it and then remove it.

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

void removeCycleLL(Node *&head)
{
    if (!head)
    {
        return;
    }

    Node *slowPtr = head;
    Node *fastPtr = head;

    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    while (fastPtr != NULL && fastPtr->next != NULL) // This is the loop where the cycle is detected:
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    slowPtr = head;
    Node *prev = fastPtr;
    while (slowPtr->next != fastPtr->next)
    {
        slowPtr = slowPtr->next;
        // prev = fastPtr;
        fastPtr = fastPtr->next;
    }
    // fastPtr = prev;
    fastPtr->next = NULL;
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
    removeCycleLL(ll1.head);
    ll1.display();

    return 0;
}