//LEETCODE 1508

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> temp;

        for(int i = 0; i < n; i++) {
            long long subarraySum = 0;
            for(int j = i; j < n; j++) {
                subarraySum += nums[j];
                temp.push_back(subarraySum);
            }
        }

        sort(temp.begin(), temp.end());

        for(int i = 0;i < temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;

        int ans = 0;
        for(int i = left - 1; i < right; i++) {
            ans = (ans + temp[i]) % MOD;
        }

        return ans;
    }
};