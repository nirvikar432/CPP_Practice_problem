#include <iostream>
#include <limits.h>
using namespace std;

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        this->top--;
        // return this->top--;
    }

    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        return this->top == -1;
    }

    int size()
    {
        return this->top + 1;
    }

    bool isFull()
    {
        return this->top == this->capacity - 1;
    }
};

int main()
{

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