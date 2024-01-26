// LEETCODE 2396

class Solution {
public:
    bool isPalindrome(int n, int base){
        vector<int> digits;

        while(n > 0){
            digits.push_back(n%base);
            n/=base;
        }

        int left = 0;
        int right = digits.size() - 1;

        while(left < right){
            if(digits[left] != digits[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;

    }
    bool isStrictlyPalindromic(int n) {
        for(int base = 2;base <= n-2;base++){
            if(!isPalindrome(n, base)){
                return false;
            }
        }
        return true;
    }
};