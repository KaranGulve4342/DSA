// LEETCODE 05

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        string maxString = "";
        for(int i = 0;i < n;i++){
            // odd length string

            int lo = i;
            int hi = i;

            while(lo >= 0 && hi < n && s[lo] == s[hi]){
                lo--;
                hi++;
            }
            string str1 = s.substr(lo + 1, hi - lo - 1);

            if(str1.length() > maxString.length()){
                maxString = str1;
            }

            // even length string
            lo = i;
            hi = i+1;

            while(lo >= 0 && hi < n && s[lo] == s[hi]){
                lo--;
                hi++;
            }

            string str2 = s.substr(lo + 1, hi - lo - 1);
            if(str2.length() > maxString.length()){
                maxString  = str2;
            }
        }
        return maxString;
    }
};