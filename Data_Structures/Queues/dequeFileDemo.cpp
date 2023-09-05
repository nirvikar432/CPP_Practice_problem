#include <iostream>
#include<deque>
using namespace std;

int main()
{

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
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