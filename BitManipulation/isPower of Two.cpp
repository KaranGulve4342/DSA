// LEETCODE 231. Power of Two

// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        // if(n == 0 || n < 0 || n%2 > 0){
        //     return false;
        // }
        // return isPowerOfTwo(n/2);

        if(n > 0 && (n&(n-1)) == 0) return true;
        return false;
    }

};