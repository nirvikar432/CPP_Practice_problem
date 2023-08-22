// Given the head of a singly linked list, reverse the list and return the reversed list. (Recursively)

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

Node *reverseLlRec(Node *&head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    Node *new_head = reverseLlRec(head->next);
    head->next->next = head;
    head->next = NULL;
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

    ll.head = reverseLlRec(ll.head);
    ll.display();

    return 0;
}