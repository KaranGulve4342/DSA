// LEETCODE 852

// BRUTE FORCE METHOD
/*
class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr){
        // 1 3 5 4 3 2 1 0

        int n = arr.size();
        int idx = -1;
        for(int i = 1;i <= n-2;i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                idx = i;
                break;
            }
        }
        return idx;
    }
};
*/

// BINARY SEARCH ALGORITHM
/*
class Solution{
public:
    int n = arr.size();
    int lo = 1;
    int hi = n-2;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid + 1]) hi = mid - 1;
        else lo = mid + 1;
    }
    return 0;
}
*/