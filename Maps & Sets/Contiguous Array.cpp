// LEETCODE 525

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int ans = 0;

        unordered_map<int, int> umap;
        umap[0] = -1;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1){
                sum += 1;
            }
            else{
                sum -= 1;
            }

            if(umap.find(sum) != umap.end()){
                int idx = umap[sum];
                int len = i - idx;
                ans = max(ans, len);
            }
            else{
                umap[sum] = i;
            }
        }
        return ans;
    }
};