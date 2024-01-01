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
