// LEETCODE 974

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;

        int currSum = 0;
        int ans = 0;

        for(auto num : nums){
            currSum += num;
            int remainder = (currSum % k + k)%k;

            if(remainderCount.find(remainder) != remainderCount.end()){
                ans += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return ans;
    }
};