// Given 2 Linked list, Tell if they are equal or not. Two linked list are equal
// if they have the same data and the arrangement of the data is also the same.

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

void checkEqualLinkedList(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    int flag = true;

    while (ptr1->next != NULL && ptr2->next != NULL)
    {
        if (ptr1->val != ptr2->val)
        {

            flag = false;
            // cout << "Not equal" << endl;
            break;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 == NULL && ptr2 == NULL && flag == true)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
}
int main()
{

    linkedList ll1;
    linkedList ll2;
    ll1.insertAtEnd(1);
    ll1.insertAtEnd(2);
    ll1.insertAtEnd(3);
    ll1.insertAtEnd(4);

    ll2.insertAtEnd(1);
    ll2.insertAtEnd(2);
    ll2.insertAtEnd(3);
    ll2.insertAtEnd(4);
    ll2.insertAtEnd(5);

    ll1.display();
    ll2.display();

    checkEqualLinkedList(ll1.head, ll2.head);

    return 0;
}