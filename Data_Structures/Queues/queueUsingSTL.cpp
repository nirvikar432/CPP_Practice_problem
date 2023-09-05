#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    cout<<qu.front()<<endl;
    qu.pop();

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    
    return 0;
}