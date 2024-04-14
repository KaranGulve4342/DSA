// LEETCODE 553

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";
        if(nums.size() == 1){
            ans += to_string(nums[0]);
            return ans;
        }
        if(nums.size() == 2){
            ans += to_string(nums[0]);
            ans += "/";
            ans += to_string(nums[1]);
            return ans;
        }

        int i = 0;
        while(i < nums.size()){
            ans += to_string(nums[i]);
            ans += "/";
            ans += "(";
            i++;

            while(i < nums.size()){
                ans += to_string(nums[i]);
                if(i != nums.size() - 1){
                    ans += "/";
                }
                i++;
            }
            ans += ")";
        }
        cout<<ans;
        return ans;
    }
};