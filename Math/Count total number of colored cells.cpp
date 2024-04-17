// LEETCODE 2579

class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return n;
        long long k = n;
        return 0LL + (1LL * (k*k)) + (1LL * ((k-1)*(k-1)));
    }
};