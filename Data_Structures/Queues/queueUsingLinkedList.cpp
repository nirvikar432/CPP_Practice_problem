#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = tail = NULL;
        size = 0;
    }

    void enqueue(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            if (head == NULL)
            {
                tail = NULL;
            }
            free(temp);
        }
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int getFront()
    {
        return head->val;
    }

    int getTail()
    {
        return tail->val;
    }
};
int main()
{
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    cout<<qu.getFront()<<endl;
    qu.dequeue();
    cout<<qu.getFront()<<endl;
    cout<<qu.getTail()<<endl;
    cout<<qu.getSize()<<endl;

    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }

    return 0;
}