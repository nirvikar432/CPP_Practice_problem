// Given the head of a sorted linked list, delete all duplicates such that each element
// appears only once. Return the loinked list sorted as well.

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

void answer(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        while (temp->next != NULL && (temp->val) == (temp->next->val))
        // while (temp->val == temp->next->val && temp->next != NULL)  THIS WILL PRODUCE AN ERROR BECAUSE IF TEMP->NEXT is NULL then TEMP->NEXT->VAL will give error.
        {
            Node *current = temp->next; // node to delete
            temp->next = temp->next->next;
            free(current);
        }
        temp = temp->next;
    }
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

    answer(ll.head);
    ll.display();
    return 0;
}