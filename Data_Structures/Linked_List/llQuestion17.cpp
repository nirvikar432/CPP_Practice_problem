// Given the head of a singly Linked list, group all the nodes with odd indices together
// followed by the nodes with even indices, and returned the reordered list.

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

Node *groupLLOddEven(Node *&head)
{
    if (!head)
    {
        return head;
    }
    Node *oddLL = head;
    Node *evenLL = head->next;
    Node *evenHead = head->next;

    while (oddLL->next && oddLL->next->next)
    {
        oddLL->next = oddLL->next->next;
        evenLL->next = evenLL->next->next;

        oddLL = oddLL->next;
        evenLL = evenLL->next;
    }
    oddLL->next = evenHead;
    return head;
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

    ll1.insertAtEnd(7);
    ll1.display();
    cout << endl;

    ll1.head = groupLLOddEven(ll1.head);
    ll1.display();

    return 0;
}