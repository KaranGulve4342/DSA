// LEETCODE 32

// EVERY PROBELM IS SOLVABLE

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int openCount = 0;
        int closeCount = 0;
        int maxi = 0;
        int right = 0;
        int left = 0;

        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                openCount++;
            }
            else if(s[i] == ')'){
                closeCount++;
            }

            if(openCount == closeCount){
                maxi = max(maxi, 2*openCount);
            }
            else if(closeCount > openCount){
                openCount = closeCount = 0;
            }
        }

        openCount = closeCount = 0;

        for(int i = n-1;i >= 0;i--){
            if(s[i] == '('){
                openCount++;
            }
            else if(s[i] == ')'){
                closeCount++;
            }

            if(openCount == closeCount){
                maxi = max(maxi, 2*closeCount);
            }
            else if(openCount > closeCount){
                openCount = closeCount = 0;
            }
        }

        return maxi;

    }
};