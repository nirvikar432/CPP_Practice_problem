// Given the head of a linked list, remove the k-th node from the end of the list and return its head.

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

void removeKNodeFromEnd(Node *head, int k)
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    while (k--)
    {
        ptr2 = ptr2->next;
    }

    if (ptr2 == NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    Node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
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

    removeKNodeFromEnd(ll1.head, 5);
    ll1.display();
    return 0;
}