// LEETCODE 2109

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0;
        int j = 0;

        while(i < s.length() && j < spaces.size()){
            if(i == spaces[j]){
                ans += " ";
                j++;
            }
            ans += s[i];
            i++;
        }
        while(i < s.length()){
            ans += s[i];
            i++;
        }
        return ans;
    }
};