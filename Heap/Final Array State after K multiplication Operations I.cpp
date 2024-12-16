// LEETCODE 3264

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0;i < n;i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto [num, idx] = pq.top();
            pq.pop();

            pq.push({num*multiplier, idx});
        }

        vector<int> ans(n, 0);

        while(!pq.empty()){
            auto [num, idx] = pq.top();
            pq.pop();

            ans[idx] = num;
        }

        return ans;
    }
};