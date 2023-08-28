// Given the head of a double linked list. The values of the linked list are stored in non-descending order.
//  Find if there exist a pair of distinct nodes such that the sum of their values is X.
//  Return the pair in the form of vector [l, r] where l and r are the values stored in the 2 nodes
//  pointed by the pointers. If there are multiple such pair return any of them. If there is no such pair return [-1, -1].

#include <iostream>
#include <vector>
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

vector<int> dllSum(Node *head, Node *tail, int x)
{
    Node *startPtr = head;
    Node *endPtr = tail;
    vector<int> ans(2, -1);

    if (head == NULL)
    {
        return ans;
    }
    while (startPtr != endPtr)
    {
        if (startPtr->val + endPtr->val < x)
        {
            startPtr = startPtr->next;
        }
        else if (startPtr->val + endPtr->val > x)
        {
            endPtr = endPtr->prev;
        }
        else if (startPtr->val + endPtr->val == x)
        {
            ans[0] = startPtr->val;
            ans[1] = endPtr->val;
            break;
        }
    }
    return ans;
}

int main()
{

    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.display();
    cout << endl;
    int val = 6;

    vector<int> ans = dllSum(dll.head, dll.tail, val);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}