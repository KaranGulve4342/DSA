// LEETCODE 3158

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> uset;

        int ans = 0;

        for(auto num : nums){
            if(uset.find(num) != uset.end()){
                ans ^= num;
            }
            else{
                uset.insert(num);
            }
        }

        return ans;
    }
};