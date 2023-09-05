#include <iostream>
#define n 10
using namespace std;

class Queue{
    int arr[n];
    int front;
    int back;
    int size;
    public:
    Queue(){
        front = 0;
        back = n-1;
        size = 0;
    }

    void enqueue(int data){
        if(isFull()) return;
            
            back = (back+1)%n;
            arr[back] = data;
            size++;

    } 

    void dequeue(){
        if(isEmpty()) return;
        front = (front+1)%n;
        size--;
        
    }

    int getSize()
    {
        return back;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getFront()
    {
        if(front == -1) return -1;
        else
        return arr[front];
    }

    int getTail()
    {
        return arr[back];
    }

    bool isFull(){
        return size ==n;
    }
};
int main()
{
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    // cout<<qu.getFront()<<endl;
    qu.dequeue();
    qu.enqueue(50);
    // cout<<qu.getFront()<<endl;
    // cout<<qu.getTail()<<endl;
    // cout<<qu.getSize()<<endl;
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);


    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    
    return 0;
}