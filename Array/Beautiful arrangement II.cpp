// LEETCODE 667

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        
        int it = 0;
        for(int i = 1;i < n-k;i++){
            ans[it] = i;
            it++;
        }

        for(int i = 0;i <= k;i++){
            ans[it] = (i%2 == 0) ? (n - k + i/2) : (n - i/2);
            it++;
        }

        return ans;

    }
};