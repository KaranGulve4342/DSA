// LEETCODE 2348

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long counter = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                counter++;
            }
            else{
                ans += (counter*(counter+1))/2;
                counter = 0;
            }
        }

        if(counter > 0){
            ans+= (counter*(counter+1))/2;
            counter = 0;
        }
        return ans;
    }
};