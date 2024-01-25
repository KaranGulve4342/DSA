#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, -2, 3, 4, 5, 6, 1, 4, -9};

    int k = 4;

    int n = sizeof(arr)/sizeof(arr[0]);

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for(int i = 0;i < n;i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(pq.size() > 0){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return 0;
}