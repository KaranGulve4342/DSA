// LEETCODE 3100

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = numBottles;
        int ans = numBottles;

        while(ans >= numExchange){
            ans -= numExchange;
            ans++;
            count++;
            numExchange++;
        }
        return count;
    }
};