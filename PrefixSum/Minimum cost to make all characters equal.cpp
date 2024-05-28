// LEETCODE 2712

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string s) {

        // std::cin.tie(nullptr);
        // std::ios_base::sync_with_stdio(false);

        // // long long ans = 0;

        // long long n = s.length();

        // // for(long long i = 1;i < n;i++){
        // //     if(s[i] != s[i-1]){
        // //         ans += min(i, n-i);
        // //     }
        // // }

        // // return ans;
        
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);

        long long n = s.length();
        
        // Prefix and suffix arrays to store the cumulative cost
        std::vector<long long> prefixSum(n, 0);
        std::vector<long long> suffixSum(n, 0);

        // Calculate prefix sums
        for (long long i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) {
                prefixSum[i] = prefixSum[i-1] + i;
            } else {
                prefixSum[i] = prefixSum[i-1];
            }
        }

        // Calculate suffix sums
        for (long long i = n-2; i >= 0; --i) {
            if (s[i] != s[i+1]) {
                suffixSum[i] = suffixSum[i+1] + (n-i-1);
            } else {
                suffixSum[i] = suffixSum[i+1];
            }
        }

        // Compute the minimum cost
        long long ans = LLONG_MAX;
        for (long long i = 0; i < n; ++i) {
            ans = std::min(ans, prefixSum[i] + suffixSum[i]);
        }

        return ans;
    }
};