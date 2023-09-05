/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example, Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

*/


#include <iostream>
#include<deque>
#include<vector>
using namespace std;


vector <int> slideWindowMaximun(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> res;

    for(int i= 0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);

    for(int i= k;i<arr.size();i++){
        int curr = arr[i];
        if(dq.front() == (i-k)) dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }

    return res;
    
}
int main()
{
    vector<int> vect{1,3,-1,-3,5,3,6,7};
    int wSize = 3;
    vector<int> ans = slideWindowMaximun(vect,wSize);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}