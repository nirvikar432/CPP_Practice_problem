#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> previousGreaterElement(vector<int> &arr){
    int size = arr.size();
    reverse(arr.begin(),arr.end());
    stack<int> index;
    vector<int> output(size,-1);
    index.push(0);
    for(int i=1;i<size;i++){
        while(!index.empty()&& arr[i]>arr[index.top()]){
            output[index.top()] = size-1-i;     //we need to store the original idx i.e idx before reverse for arr.
            index.pop();

        }
        index.push(i);
    }

    reverse(output.begin(),output.end());   //to get previous greater element output idx
    reverse(arr.begin(),arr.end()); // To get the original array

    return output;
}

int main()
{
    int n;
    cout << "Enter vector Size : ";
    cin >> n;
    vector<int> input;
    while (n--)
    {
        int inp;
        cin >> inp;
        input.push_back(inp);
    }

    vector<int> result = previousGreaterElement(input);

    cout<<"nextGreaterElement"<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << i-result[i] << " ";
    }
    cout<<endl;
    return 0;
}



//7
// 100 80 60 70 60 75 85