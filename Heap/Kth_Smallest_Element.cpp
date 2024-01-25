// Approach 1 - 
// TC = O(n.log(n))

/*
class Solution{
    public:

    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r - l + 1;
        sort(arr + l,arr+r+1);
        return arr[l + k - 1];
    }
};
*/
// using maxHeap
/*
int kthSmallest(int arr[], int l, int r, int k){
    priority_queue<int> pq;

    // step 1
    for(int i = 0;i < k;i++){
        pq.push(arr[i]);
    }

    // step 2
    for(int i = k;i <= r;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // ans = pq.top()
    int ans = pq.top();
    return ans;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, -2, 3, 4, 5, 6, 1, 4, -9};

    int k = 4;

    int n = sizeof(arr)/sizeof(arr[0]);

    priority_queue<int> pq;
    for(int i = 0;i < n;i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }

    cout<<pq.top();
    
    return 0;
}