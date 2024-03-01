// LEETCODE 1930

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(auto ch : s){
            letters.insert(ch);
        }

        int ans = 0;
        for(char letter : letters){
            int i = -1;
            int j = 0;

            for(int k = 0;k < s.length();k++){
                if(s[k] == letter){
                    if(i == -1){
                        i = k;
                    }
                    j = k;
                }
            }

            unordered_set<char> between;
            for(int k = i+1;k < j;k++){
                between.insert(s[k]);
            }

            ans += between.size();
        }
        return ans;
    }
};