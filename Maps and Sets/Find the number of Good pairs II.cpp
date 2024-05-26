// LEETCODE 3164

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, long long> umap;
        long long ans = 0;

        for(long long num : nums2){
            umap[num]++;
        }

        for(int num1 : nums1){
            if(num1 % k == 0){
                int target = num1 / k;
                for(int factor = 1;factor * factor <= target;factor++){
                    if(target % factor == 0){
                        ans += umap[factor];

                        if(factor != target/factor){
                            ans += umap[target / factor];
                        }
                    }
                }
            }
        }
        return ans;
    }
};