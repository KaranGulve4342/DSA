// LEETCODE 2240

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        long long penCost = 0;

        while(penCost <= total){
            long long remaining = total - penCost;
            long long pencils = 1 + remaining/cost2;
            ways += pencils;
            penCost += cost1;
        }
        return ways;
    }
};