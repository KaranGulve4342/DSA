class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n-k+1);

        for(int i = 0;i < n-k+1;i++){
            map<int, int> mp;
            for(int j = i;j < i+k;j++){
                mp[nums[j]]++;
            }

            vector<pair<int, int>> vp;
            for(auto it : mp){
                vp.push_back({it.second, it.first});
            }

            sort(vp.begin(), vp.end(), greater<pair<int, int>>());

            for(int j = 0;j < vp.size() && j < x;j++){
                ans[i] += (vp[j].first * vp[j].second);
            }
        }
        return ans;
    }
};