// LEETCODE 2597

class Solution {
public:
    bool check(int x, int k, vector<int>& v){
        for(auto element : v){
            if(abs(element - x) == k) return false;
        }
        return true;
    }
    void solve(int idx, vector<int>& nums, int k, vector<int>& v, int &ans){
        if(idx == nums.size()){
            ans++;
            return;
        }

        if(check(nums[idx], k, v)){
            v.push_back(nums[idx]);
            solve(idx + 1, nums, k, v, ans);
            v.pop_back();
        }

        solve(idx + 1, nums, k, v, ans);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = -1;
        vector<int> v;
        solve(0, nums, k, v, ans);
        return ans;
    }
};