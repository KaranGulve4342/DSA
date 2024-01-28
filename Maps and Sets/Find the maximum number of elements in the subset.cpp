// LEETCODE 3020

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumLength(vector<int>& nums){
        long long n = nums.size();

        long long mx = 1;

        sort(nums.begin(), nums.end());

        unordered_map<long long, long long> umap;

        for(auto num : nums){
            umap[num]++;
        }

        for(int i = 0; i < n;i++){
            long long curr = nums[i];

            long long curr_max = 0;

            while(umap[curr] > 0){
                if(umap[curr] < 2){
                    curr_max += umap[curr];
                    umap[curr] = 0;
                    break;
                }

                curr_max += 2;

                umap[curr] -= 2;

                curr *= curr;
            }

            if(curr_max % 2 == 0){
                mx = max(mx, curr_max - 1);
            }
            else{
                mx = max(mx, curr_max);
            }
        }

        return mx;
    }
};