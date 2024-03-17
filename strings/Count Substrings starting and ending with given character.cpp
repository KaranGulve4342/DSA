// LEETCODE 3084

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        
        int c_count = 0;
        for (char ch : s) {
            if (ch == c){
                c_count++;
            }
        }
        if (c_count == 0){
            return 0;
        }
        ans = (long long)c_count * (c_count + 1) / 2;
        return ans;
        
    }
};