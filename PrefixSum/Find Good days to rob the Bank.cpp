// LEETCODE 2100

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int time) {
        int n = arr.size();

        vector<int> left(n, 1);
        for(int i = 1;i < n;i++){
            if(arr[i] <= arr[i-1]){
                left[i] = left[i-1] + 1;
            }
        }

        vector<int> right(n, 1);
        for(int i = n-2;i >= 0;i--){
            if(arr[i] <= arr[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        vector<int> ans;
        for(int i = time;i <= n - time - 1;i++){
            if(left[i] >= time+1 && right[i] >= time+1){
                ans.push_back(i);
            }
        } 
        return ans;
    }
};