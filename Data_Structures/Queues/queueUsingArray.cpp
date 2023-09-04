#include <iostream>
#define n 10
using namespace std;

class Queue{
    int arr[n];
    int front;
    int back;
    public:
    Queue(){
        front = back = -1;
    }

    void enqueue(int data){
        if(front == -1){
            // front++;
            arr[++front] = data;
            back++;
        }
        else{
            arr[++back] = data;
        }
    }

    void dequeue(){
        if(front == -1){
            return;
        }
        else if(front == back){
            front = back = -1;
            
        }
        else{
            front++;
        }
    }

    int getSize()
    {
        return back;
    }

    bool isEmpty()
    {
        return front ==-1;
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
    // cout<<qu.getFront()<<endl;
    // cout<<qu.getTail()<<endl;
    // cout<<qu.getSize()<<endl;
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);
    qu.enqueue(600);
    qu.dequeue();

    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    
    return 0;
}