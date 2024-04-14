// LEETCODE 3110

class Solution {
public:
    int scoreOfString(string s) {
        long long sum = 0;
        for(int i = 1;i < s.length();i++){
            sum += abs(s[i] - s[i-1]);
        }
        return sum;
    }
};