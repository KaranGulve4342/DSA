// LEETCODE 3019

class Solution {
public:
    int countKeyChanges(string s) {
        int keyChanges = 0;
        
        // for (int i = 1; i < s.length(); ++i) {
        //     // Compare current character and previous character, ignoring case
        //     if (tolower(s[i]) != tolower(s[i - 1])) {
        //         ++keyChanges;
        //     }
        // }

        for(int i = 1;i < s.length();i++){
            if(s[i] != s[i-1] && abs(s[i] - s[i-1]) != abs('a' - 'A')){
                keyChanges++;
            }
        }
        
        return keyChanges;
    }
};