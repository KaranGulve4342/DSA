// LEETCODE 2275

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int maxAND;
    // void solve(vector<int>& candidates, int idx, int curr, int count){
    //     if(idx == candidates.size()){
    //         if(curr > 0){
    //             maxAND = max(maxAND, count);
    //         }
    //         return;
    //     }

    //     solve(candidates, idx + 1, curr & candidates[idx], count + 1);
    //     solve(candidates, idx + 1, curr, count);
    // }
    int largestCombination(vector<int>& candidates) {
        // maxAND = 0;
        // solve(candidates, 0, INT_MAX, 0);

        // return maxAND;

        vector<int> bits(24, 0);
        for(auto &candidate : candidates){
            int i = 0;
            while(candidate > 0){
                if((candidate & 1) == 1){
                    bits[i]++;
                }
                candidate >>= 1;
                i++;
            }
        }

        int maxBit = 0;
        for(auto &bit : bits){
            maxBit = max(maxBit, bit);
        }
        return maxBit;
    }
};