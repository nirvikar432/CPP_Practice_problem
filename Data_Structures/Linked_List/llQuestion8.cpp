// Given the heads of two singly linked lists headA and headB, return the node at which the two lists intersect,
//  If the two linked lista have no intersections at all return null

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

int getLengthOfLL(Node *head)
{
    Node *ptr = head;
    int length = 0;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}

Node *moveHeadByK(Node *head, int k)
{
    Node *temp = head;
    while (k--)
    {
        temp = temp->next;
    }
    return temp;
}

Node *intersectionPoint(Node *head1, Node *head2)
{
    int l1 = getLengthOfLL(head1);
    int l2 = getLengthOfLL(head2);

    Node *ptr1, *ptr2;

    if (l1 > l2)
    {
        int k = l1 - l2;
        ptr1 = moveHeadByK(head1, k);
        ptr2 = head2;
    }
    else
    {
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveHeadByK(head2, k);
    }

    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
int main()
{

    linkedList ll1;
    linkedList ll2;
    ll1.insertAtEnd(1);
    ll1.insertAtEnd(2);
    ll1.insertAtEnd(3);
    ll1.insertAtEnd(4);
    ll1.insertAtEnd(5);
    ll1.display();

    ll2.insertAtEnd(6);
    ll2.insertAtEnd(7);
    ll2.head->next->next = ll1.head->next->next->next;
    Node *intersection = intersectionPoint(ll1.head, ll2.head);
    ll2.display();
    if (intersection)
    {
        cout << intersection->val << endl;
    }
    else
        cout << "-1" << endl;

    return 0;
}