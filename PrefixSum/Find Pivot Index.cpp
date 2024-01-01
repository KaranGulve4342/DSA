// Leetcode 724

/*
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_Sum(n);
        int idx = -1;
        if(n == 0) return idx;
        if(n == 1){
            idx = 0;
            return idx;
        } 

        prefix_Sum[0] = nums[0];
        for(int i = 1;i < n;i++){
            prefix_Sum[i] = nums[i] + prefix_Sum[i - 1];
        }
        for(int i = 1;i < n;i++){
            if(prefix_Sum[n-1] == prefix_Sum[0]) return 0;
            if(prefix_Sum[i-1] == prefix_Sum[n-1]-prefix_Sum[i]){
                idx = i;
                return idx;
            }  
        }
        return -1;


    }
};
*/