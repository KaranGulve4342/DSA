// LEETCODE POTD 15TH NOV 2024 1574

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;

        while(lo + 1 < n && arr[lo] <= arr[lo+1]){
            lo++;
        }

        if(lo == n-1){
            return 0;
        }

        while(hi > lo && arr[hi] >= arr[hi-1]){
            hi--;
        }

        int ans = min(n-lo-1, hi);

        int i = 0;
        int j = hi;

        while(i <= lo && j < n){
            if(arr[i] <= arr[j]){
                ans = min(ans, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};