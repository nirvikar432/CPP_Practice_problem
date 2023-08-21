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

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insertAtPos(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }
    Node *new_node = new Node(val);
    Node *temp = head;
    int currentPos = 0;
    while (currentPos != pos - 1)
    {
        temp = temp->next;
        currentPos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtPos(Node *&head, int val, int pos)
{

    Node *temp = head;
    int currentPos = 0;
    while (currentPos != pos)
    {
        temp = temp->next;
        currentPos++;
    }

    temp->val = val;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node *&head)
{
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *dNode = temp->next;
    temp->next = NULL;
    free(dNode);
}

void deleteAtPos(Node *head, int pos)
{
    if (pos == 0)
    {
        deleteAtHead(head);
        return;
    }
    int currentPos = 0;
    Node *temp = head;
    while (currentPos != pos - 1)

    {
        temp = temp->next;
        currentPos++;
    }
    Node *dNode = temp->next;
    temp->next = temp->next->next;
    free(dNode);
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // Node *n = new Node(1);
    // cout << n->val << " " << n->next << endl;
    Node *head = NULL;
    insertAtHead(head, 1);
    display(head);
    insertAtHead(head, 0);
    display(head);
    insertAtEnd(head, 3);
    display(head);
    insertAtPos(head, 99, 1);
    display(head);
    updateAtPos(head, 20, 2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtEnd(head);
    display(head);
    insertAtEnd(head, 80);
    display(head);
    deleteAtPos(head, 1);
    display(head);

    return 0;
}