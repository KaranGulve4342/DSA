// LEETCODE 658


// SC = O(k)
// TC = O(log(n) + k.log(k))
/*
class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        int n = arr.size();
        vector<int> ans(k); // k elements ko insert karoonga
        if(x < arr[0]){
            for(int i = 0;i < k;i++){
                ans[i] = arr[i];
            }
            return ans;
        }
        if(x > nums[n-1]){
            int i = n - 1;
            int j = k - 1;
            while(j >= 0){
                ans[j] = arr[i];
                j--;
                i--;
            }
            return ans;
        }
        int lo = 0;
        int hi = n - 1;
        bool flag = false;
        int t = 0; // representing index of ans
        int mid = -1;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(arr[mid] == x){
                flag = true; // present
                ans[t] = arr[mid];
                t++;
                break;
            }
            else if(arr[mid] > x) hi = mid - 1;
            else lo = mid + 1;
        }
        int lb = hi;
        int ub = lo;
        if(flag == true){
            lb = mid - 1;
            ub = mid + 1;
        }
        while(t < k && lb >= 0 && ub <= n-1){
            int d1 = abs(x - arr[lb]);
            int d2 = abs(x - arr[ub]);
            if(d1 <= d2){
                ans[t] = arr[lb];
                lb--;
            }
            else{
                // d1 < d2
                ans[t] = arr[ub];
                ub++;
            }
            t++;
        }
        if(lb < 0){
            while(t < k){
                ans[t] = arr[ub];
                ub++;
                t++;
            }
        }
        while(ub > n-1){
            while(t < k){
                ans[t] = arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(), ans.end());

    }
}
*/

/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while(left < right){
            int mid = left + (right - left)/2;

            if(x - arr[mid] > arr[mid + k] - x){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
*/