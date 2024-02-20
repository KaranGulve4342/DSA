// LEETCODE 17

class Solution {
public:
    unordered_map<char, string> umap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int idx, string digits, string str, vector<string>& ans){
        if(idx == digits.length()){
            ans.push_back(str);
            return;
        }

        char digit = digits[idx];
        string letters = umap[digit];
        for(char c : letters){
            solve(idx + 1, digits, str + c, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }

        solve(0, digits, "", ans);
        return ans;
    }
};