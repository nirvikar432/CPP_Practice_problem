// You are given an array of K linked lists lists, each linked list is sorted in ascending order.
// Merge all the linked list into the one sorted linked list and return it

#include <iostream>
#include <vector>
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

Node *mergedLL(Node *&head1, Node *&head2)
{
    Node *dummyhead = new Node(-1);

    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *ptr3 = dummyhead;

    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
    }
    while (ptr1)
    {
        ptr3->next = ptr1;
        break;
    }
    while (ptr2)
    {
        ptr3->next = ptr2;
        break;
    }

    dummyhead = dummyhead->next;
    return dummyhead;
}

Node *mergeKLL(vector<Node *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }
    while (lists.size() > 1)
    {
        Node *mergedHead = mergedLL(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main()
{
    linkedList ll1;
    ll1.insertAtEnd(1);
    ll1.insertAtEnd(3);
    ll1.insertAtEnd(5);
    ll1.insertAtEnd(7);
    ll1.display();

    linkedList ll2;
    ll2.insertAtEnd(0);
    ll2.insertAtEnd(2);
    ll2.insertAtEnd(4);
    ll2.insertAtEnd(6);
    ll2.display();

    linkedList ll3;
    ll3.insertAtEnd(8);
    ll3.insertAtEnd(9);
    ll3.insertAtEnd(10);
    ll3.insertAtEnd(12);
    ll3.display();

    vector<Node *> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);

    linkedList mergedLinkedList;
    mergedLinkedList.head = mergeKLL(lists);
    mergedLinkedList.display();

    return 0;
}