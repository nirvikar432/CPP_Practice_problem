// Given the head of a doubly linked list, delete the nodes whose neighbours have the same values. Traverse the list from right to left.

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
};

void checkNeighbour(Node *&head, Node *&tail)
{
    Node *cPtr = tail->prev;

    while (cPtr != head)
    {
        Node *nPtr = cPtr->prev;
        Node *pPtr = cPtr->next;
        if (pPtr->val == nPtr->val)
        {
            nPtr->next = pPtr;
            pPtr->prev = nPtr;
            free(cPtr);
        }
        cPtr = nPtr;
    }
}

int main()
{

    DoublyLinkedList dll;
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    cout << endl;
    checkNeighbour(dll.head, dll.tail);
    dll.display();

    return 0;
}