// LEETCODE 858

class Solution {
public:
    int mirrorReflection(int p, int q) {

        int lcm = (p*q)/__gcd(p, q);
        p = lcm/p;
        q = lcm/q;

        if(p%2 == 0 && q%2 == 1) return 0;
        if(p%2 == 1 && q%2 == 1) return 1;
        if(p%2 == 1 && q%2 == 0) return 2;
        return -1;
    }
};