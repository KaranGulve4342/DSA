// LEETCODE 70

/*
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        vector<int> steps(n+1, 0);
        steps[1] = 1;
        steps[2] = 2;

        for(int i = 3;i <= n;i++){
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n]; 
    }
};
*/

/*
class Solution {
public:
    int climbStairs(int n){
        vector<int> cost(n+1, 0);
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2;i < n;i++){
            int curr = cost[i] + min(orev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
}
*/