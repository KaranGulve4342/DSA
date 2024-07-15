// LEETCODE 214

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int i = 0;

        for(int j = n-1;j >= 0;j--){
            if(s[i] == s[j]){
                i++;
            }
        }

        if(i == n){
            return s;
        }

        string remain = s.substr(i, n);
        string rev_remain = remain;
        reverse(rev_remain.begin(), rev_remain.end());

        return rev_remain + shortestPalindrome(s.substr(0, i)) + s.substr(i);

    }
};