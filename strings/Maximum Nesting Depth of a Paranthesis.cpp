// LEETCODE 1614

class Solution {
public:
    int maxDepth(string s) {
        int countOpen = 0;
        int countClose = 0;

        int ans = INT_MIN;

        for(int i = 0;i < s.length();i++){
            if(s[i] == '('){
                countOpen++;
            }
            else if(s[i] == ')'){
                countClose++;
            }
            
            ans = max(ans, countOpen - countClose);
        }
        return ans == INT_MIN ? 1 : ans;
    }
};