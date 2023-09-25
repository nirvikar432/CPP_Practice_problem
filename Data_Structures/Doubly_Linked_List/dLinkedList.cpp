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

    void insertAtHead(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
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

    void insertAtKPos(int val, int k)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        Node *temp = head;
        int count = 1;
        while (count < k - 1)
        {
            temp = temp->next;
            count++;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;

        return;
    }

    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtPos(int k)
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        int counter = 1;
        while (counter < k)
        {
            temp = temp->next;
            counter++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
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

int main()
{

    Node *new_node = new Node(3);

    DoublyLinkedList dll;
    // dll.head = new_node;
    // dll.tail = new_node;

    // cout << dll.head->val << endl;

    // dll.insertAtHead(1);
    // dll.insertAtHead(2);
    // dll.insertAtHead(3);
    // dll.insertAtHead(4);

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    // dll.insertAtEnd(5);
    // dll.insertAtEnd(6);

    // dll.insertAtKPos(20, 3);
    dll.display();

    // dll.deleteAtStart();
    // dll.display();

    // dll.deleteAtEnd();
    // dll.display();
    dll.deleteAtPos(2);
    dll.display();

    return 0;
}