// LEETCODE 2864

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();

        int countOnes = 0;
        for(auto ch : s){
            countOnes += ch - '0';
        }   

        string ans = "";
        for(int i = 0;i < countOnes - 1;i++){
            ans += '1';
        }
        for(int i = 0;i < len - countOnes;i++){
            ans += '0';
        }

        ans += '1';

        return ans;

    }
};