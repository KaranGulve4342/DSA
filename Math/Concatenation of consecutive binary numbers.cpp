// LEETCODE 1680

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int length = 0; // Number of bits in the current binary representation
        
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) { // Check if i is a power of 2
                ++length;
            }
            result = ((result << length) + i) % MOD; // Shift result left by length and add i
        }
        
        return result;
    }
};