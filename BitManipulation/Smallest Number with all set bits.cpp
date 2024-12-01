// LEETCODE 3370

class Solution {
public:
    int smallestNumber(int n) {

        while(true){
            if((n&(n+1)) == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};