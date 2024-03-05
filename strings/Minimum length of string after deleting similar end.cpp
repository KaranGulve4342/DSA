// LEETCODE 1750

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length() - 1;
        int left = 0;
        int right = n;
        if(s[left] != s[right]){
            return s.length();
        }

        while(left < right && s[left] == s[right]){
            char prefix = s[left];

            while(left <= right && s[left] == prefix){
                left++;
            }

            while(right > left && s[right] == prefix){
                right--;
            }
        }

        return right - left + 1;
    }
};