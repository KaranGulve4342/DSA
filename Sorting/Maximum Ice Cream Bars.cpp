// LEETCODE 1833

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        if(costs[0] > coins) return 0;
        int count = 0;
        for(int i = 0;i < costs.size();i++){
            if(coins>=costs[i]){
                count++;
                coins-=costs[i];
            }
            if(coins<=0){
                return count;
            }
        }

        return count;
    }
};