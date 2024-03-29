// LEETCODE 2962

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int i = 0;

        for(int j = 0;j < nums.size();j++){
            if(nums[j] == maxi){
                k--;
            }
            while(k == 0){
                if(nums[i] == maxi){
                    k++;
                }
                i++;
            }
            ans += i;
        }
        return ans;
    }
};