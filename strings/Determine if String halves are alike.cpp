// LEETCODE 1704

class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;

        for(int i = 0;i < s.length()/2;i++){
            if(isVowel(s[i])){
                count1++;
            }
        }
        for(int i = s.length()/2;i < s.length();i++){
            if(isVowel(s[i])){
                count2++;
            }
        }

        return (count1 == count2) ? true : false;
    }
};