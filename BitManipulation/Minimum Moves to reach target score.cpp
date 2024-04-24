// LEETCODE 2139

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int num = 1;
        int count = 0;
        while(maxDoubles && target > num){
            if(target&1){
                --target;
                count++;
            }
            target /= 2;
            maxDoubles--;
            count++;
        }
        if(num < target){
            count += target-num;
        }
        return count;
    }
};