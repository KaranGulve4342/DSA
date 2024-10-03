// LEETCODE 1590

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;
        for(auto el: nums) target = (target + el) % p;
        unordered_map<int, int> mp; 
        mp[0] = -1; 
        int cur = 0;
        int ans = 1e9;
        if(!target) return 0;
        for(int i = 0; i<n; i++){
            
            cur = (cur + nums[i]) % p;
            
            int need = (cur - target + p) % p; 
            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }
            mp[cur] = i; 
        
        }
        
        if(ans >= n) return -1;
        return ans;
    }
};