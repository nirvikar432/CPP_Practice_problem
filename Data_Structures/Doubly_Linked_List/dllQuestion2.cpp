// Given the head of a doubly linked list, find if it's palindrome or not.

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

bool palindromeCheck(Node *head, Node *tail)
{
    Node *headPtr = head;
    Node *tailPtr = tail;

    while (headPtr != tailPtr && tailPtr != headPtr->prev)
    {
        if (headPtr->val != tailPtr->val)
        {
            return false;
        }
        else
        {
            headPtr = headPtr->next;
            tailPtr = tailPtr->prev;
        }
    }
    return true;
}
int main()
{

    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(3);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    cout << endl;
    cout << palindromeCheck(dll.head, dll.tail);

    return 0;
}