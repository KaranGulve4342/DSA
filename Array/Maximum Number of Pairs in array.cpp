// LEETCODE 2341

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> umap;

        int n = nums.size();
        for(int i = 0;i < n;i++){
            umap[nums[i]]++;
        }
        int count = 0;
        for(auto x : umap){
            if(x.second >= 2){
                count+= (x.second/2);
            }
        }

        return {count, n - (2*count)};
    }
};