 // LEETCODE 1957

 class Solution {
public:
    string makeFancyString(string s) {
        int count = 1;
        string ans = "";

        ans.push_back(s[0]);

        for(int i = 1;i < s.length();i++){
            if(s[i] == s[i-1]){
                count += 1;
            }
            else{
                count = 1;
            }

            if(count < 3){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};