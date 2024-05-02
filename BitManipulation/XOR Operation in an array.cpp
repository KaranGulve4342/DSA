// LEETCODE 1486

class Solution {
public:
    int xorOperation(int n, int start) {
        int i = 1;
        int ans = start;
        while(i < n){
            ans ^= (start + (2*i));
            i++;
        }
        return ans;
    }
};