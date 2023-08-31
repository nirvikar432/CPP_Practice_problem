#include<iostream>
#include<limits.h>
using namespace std;


class Node{
    public:
    int val;
    Node *next;

    Node(int data){
        val = data;
        next = NULL;
    }
};


class Stack{
    Node * head;
    int capacity;
    int currSize ;
    public:
    Stack(int c){
        capacity = c;
        currSize = 0;
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;;
    }

    bool isFull(){
        return currSize== capacity;
    }

    void push(int data){
        if(currSize== capacity){
            cout<<"Overflow"<<endl;
            return;

        }
        Node * new_node = new Node(data);
        Node * temp = head;
        new_node->next = head;
        head = new_node;
        currSize++;

    }

    int pop(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;

        }
        Node * temp = head;
        head = head->next;
        int value = temp->val;
        free(temp);
        currSize--;
        return value;

    }

    int size(){
        return currSize;
    }

    int getTop(){
        return head->val;
    }

};

int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.getTop() << endl;
    st.pop();
    cout << st.getTop() << endl;
    st.push(20);
    st.isEmpty();
    st.isFull();
    cout << st.getTop();

    return 0;
}