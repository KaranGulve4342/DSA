// LEETCODE 2914

class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int consecutiveCount = 0;
        int ans = 0;

        for(int i = 0;i < s.length();i++){
            if(s[i] == curr){
                consecutiveCount++;
                continue;
            }

            if(consecutiveCount%2 == 0){
                consecutiveCount = 1;
            }
            else{
                consecutiveCount = 0;
                ans++;
            }

            curr = s[i];
        }

        return ans;
    }
};