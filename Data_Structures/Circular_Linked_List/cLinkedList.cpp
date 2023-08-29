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

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    void insertAtStart(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void insertAtEnd(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
    }

    void insertAtPos(int val, int pos)
    {
        Node *new_node = new Node(val);
        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node *temp = head;
        int counter = 0;
        while (counter != pos - 1)
        {
            temp = temp->next;
            counter++;
        }
        new_node->next = temp->next;
        temp->next = new_node; // 0   1   2   3   4   5   6   7
    }

    void display()
    {
        Node *temp = head;
        do
        {

            cout << temp->val << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{

    CircularLinkedList cll;
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.insertAtStart(20);
    cll.insertAtPos(30, 4);
    cll.display();
    return 0;
}