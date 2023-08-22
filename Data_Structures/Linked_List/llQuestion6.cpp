// Given the head of a LL, reverse the nodes of the list k at a time, and return the modified list.

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

Node *reverseLlK(Node *&head, int k)
{
    Node *p = NULL;
    Node *c = head;
    int count = 0;
    while (c != NULL && count < k)
    {
        Node *n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }

    if (c != NULL)
    {
        Node *new_head = reverseLlK(c, k); // Recursively reverse the next group and update head

        head->next = new_head;
    }

    return p; // p is the new head of the reversed group
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

    ll.head = reverseLlK(ll.head, 2); // Update the head with the new head
    ll.display();

    return 0;
}