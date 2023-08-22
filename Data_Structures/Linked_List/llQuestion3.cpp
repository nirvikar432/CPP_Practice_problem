// Given the head of a singly linked list and print the reversed list.

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

void reversePrint(Node *head)
{

    if (head == NULL)
    {
        cout << "NULL";
        return;
    }

    reversePrint(head->next);

    cout << "->" << head->val;
}
int main()
{

    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(3);
    ll.insertAtEnd(3);
    ll.display();

    reversePrint(ll.head);
    // ll.display();

    return 0;
}