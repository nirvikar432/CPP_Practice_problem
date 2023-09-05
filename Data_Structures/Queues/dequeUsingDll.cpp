#include <iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int val;
    Node* next;
    Node(int data){
        prev = NULL;
        val = data;
        next=NULL;
    }
};

class deque{
    

    public:
    Node *head;
    Node *tail;

    deque()
    {
        head = NULL;
        tail = NULL;
    }
    void push_back(int val){
        Node * new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        else{
            tail->next = new_node;
            new_node -> prev = tail;
            tail = new_node;
            return;
        }

    }

    void push_front(int val){
        Node * new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        else{
            new_node->next = head;
            head -> prev = new_node;
            head = new_node;
            return;
        }
    }

    void pop_back(){
        if(head == NULL){
            return;
        }
        else{
            Node * temp = tail;
            tail = tail->prev;
            if(tail==NULL){
                head = NULL;
                return;
            }
            else{
                tail->next= NULL;
            }
            free(temp);
            return;
        }

    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        else{
            Node * temp = head;
            head = head->next;
            if(head==NULL){
                tail = NULL;
                return;
            }
            else{
                head->prev= NULL;
            }
            free(temp);
            return;
        }

    }

    bool empty(){
        return head == NULL;
    }

    int front(){
        return head->val;
    }
};

int main()
{

    deque dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    // cout<<dq.empty();
    // cout<<dq.front();
    // dq.pop_back();
    // dq.pop_front();

    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }

    cout<<endl;



    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);

    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    
    return 0;
}