// Give the head of a linked list, rotate the list to the right by K places.

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
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

Node *rotateLLByKBrute(Node *&head, int k) // Brute force approach
{
    Node *temp = head;
    Node *prev = head;
    while (k--)
    {
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;

        temp->next = head;
        head = temp;
    }
    return head;
}

Node *rotateLLByK(Node *&head, int k)
{
    Node *tail = head;
    int counter = 1;
    while (tail->next)
    {
        tail = tail->next;
        counter++;
    }

    k %= counter;
    if (k == 0)
    {
        return head;
    }

    tail->next = head;
    Node *temp = head;
    for (int i = 1; i < counter - k; i++)
    {
        temp = temp->next;
    }
    Node *newHead = temp->next;
    temp->next = NULL;
    return newHead;
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
    // Node *newHead = rotateLLByKBrute(ll1.head, 2);

    ll1.head = rotateLLByK(ll1.head, 8);

    cout << endl;
    ll1.display();

    return 0;
}