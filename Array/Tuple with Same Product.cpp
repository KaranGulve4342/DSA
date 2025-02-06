// LEETCODE 1726

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        int ans = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                int prod = nums[i] * nums[j];

                umap[prod]++;
            }
        }

        for(auto x : umap){
            int n = x.second;

            ans += (n*(n-1)/2);
        }
        return ans*8;
    }
};