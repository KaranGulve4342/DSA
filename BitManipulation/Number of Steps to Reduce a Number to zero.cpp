// LEETCODE 1342

class Solution {
public:
    int numberOfSteps(int num) {
        // int count = 0;
        // while(num != 0){
        //     if(num & 1){
        //         num -= 1;
        //         count++;
        //     }
        //     else{
        //         // num /= 2;
        //         num >>= 1;
        //         count++;
        //     }
        // }
        // return count;

        // return num > 0 ? 31 - __builtin_clz(num) + bitset<32>(num).count() : 0;
        return num > 0 ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
    }
};