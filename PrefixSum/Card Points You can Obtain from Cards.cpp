//  LEETCODE 1423

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> prefixSum(k+1, 0);
        vector<int> suffixSum(k+1, 0);

        for (int i = 0; i < k; i++) {
            prefixSum[i+1] = prefixSum[i] + cardPoints[i];
        }

        for (int i = 0; i < k; i++) {
            suffixSum[i+1] = suffixSum[i] + cardPoints[n-1-i];
        }

        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, prefixSum[i] + suffixSum[k-i]);
        }

        return ans;
    }
};