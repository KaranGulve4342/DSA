// LEETCODE 3216

class Solution {
public:
    string getSmallestString(string s) {
        string mini = s;
        int n = s.length();

        for(int i = 0;i < n-1;i++){
            if(s[i]%2 == s[i+1]%2){
                if(s[i] > s[i+1]){
                    string temp = s;
                    swap(temp[i], temp[i+1]);
                    mini = min(mini, temp);
                }
            }
        }

        return mini;
    }
};