// LEETCODE 862

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = INT_MAX;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        long long sum = 0;

        for(long long i = 0;i < n;i++){
            sum += (long long)nums[i];

            if(sum >= (long long)k){
                ans = min(ans, (int)i+1);
            }

            while(!pq.empty() && (sum-pq.top().first >= k)){
                auto p = pq.top();
                ans = min(ans, (int)(i-p.second));
                pq.pop();
            }

            pq.push({sum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};