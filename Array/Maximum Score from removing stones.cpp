// LEETCODE 1753

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int maxi = max({a, b, c});
        int mini = min({a, b, c});

        int middle = a + b + c - maxi - mini;

        if(mini + middle < maxi){
            return mini + middle;
        }
        return (a + b + c)/2;
    }
};