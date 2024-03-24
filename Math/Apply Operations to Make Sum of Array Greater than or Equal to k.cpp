// LEETCODE 3091

class Solution {
public:
    int minOperations(int k) {
        if (k == 1) return 0;
        
        long long a = (long long)sqrt(k);
        long long b = k / a;
        
        while (a * b < k) {
            a++;
        }
        
        return a + b - 2;
    }
};