// A critical point in a linked list is defined as either a local maxima or a local minima.
// Given a linked list tail, return an array of length 2 containing [min distance, max distance]
// where minDistance is the minimum distance between any two distinct critical points and maxDistance
// is maximum distance between any two distinct critical points.
// If there are fewer than two critical points, return [-1,-1].
// Note that a node can only be a local maxima/minima if there exist both previous node and next node.

#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
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

// void findLocalMaxMin(Node *&head, Node *&tail)
// {
//     Node *temp = head->next;
//     int maxima = 0, minima = 0;

//     while (temp->next)
//     {
//         if (temp->prev->val < temp->val && temp->val > temp->next->val)     //MAXIMA
//         {
//             maxima = temp->val;
//             temp = temp->next;
//         }
//         else if (temp->prev->val > temp->val && temp->val < temp->next->val)        //MINIMA
//         {
//             minima = temp->val;
//             temp = temp->next;
//         }
//         else            //!MAXIMA OR MINIMA
//         {
//             maxima = -1;
//             minima = -1;
//             temp = temp->next;
//         }
//     }
//     cout << "[" << maxima << "," << minima << "]" << endl;
// }

bool isCriticalPoint(Node *&cNode)
{
    if (cNode->prev->val < cNode->val && cNode->val > cNode->next->val)
    {
        return true;
    }
    else if (cNode->prev->val > cNode->val && cNode->val < cNode->next->val)
    {
        return true;
    }

    return false;
}

vector<int> distanceBetMaxMin(Node *head, Node *tail)
{
    vector<int> ans(2, INT_MAX);

    int fCp = -1;
    int lCp = -1;

    Node *cNode = tail->prev;
    if (cNode == NULL)
    {
        ans[0] = ans[1] = -1;
        return ans;
    }

    int pos = 0;
    while (cNode->prev)
    {
        if (isCriticalPoint(cNode))
        {
            if (fCp == -1)
            {
                fCp = lCp = pos;
            }
            else
            {
                ans[0] = min(ans[0], pos - lCp); // Minimum distance
                ans[1] = pos - fCp;              // Maximum distance
                lCp = pos;
            }
        }
        pos++;
        cNode = cNode->prev;
    }
    if (ans[0] == INT_MAX)
    {
        ans[0] = ans[1] = -1;
    }
    return ans;
}

int main()
{

    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(5);
    dll.insertAtEnd(4);
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);

    dll.display();
    cout << endl;
    vector<int> ans = distanceBetMaxMin(dll.head, dll.tail);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}