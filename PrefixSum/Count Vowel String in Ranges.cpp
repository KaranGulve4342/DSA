// LEETCODE 2559

class Solution {
public:
    bool isok(string str){
        int n = str.length();
        if (
            (str[0] == 'a' || str[0] == 'e' || str[0] == 'o' || str[0] == 'i' || str[0] == 'u') && 
            (str[n-1] == 'a' || str[n-1] == 'e' || str[n-1] == 'o' || str[n-1] == 'i' || str[n-1] == 'u')
        ) {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> check(words.size(), false);

        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            if (isok(word)) {
                check[i] = true;
            }
        }
        
        vector<int> prefixSum(words.size(), 0);
        prefixSum[0] = check[0] == true ? 1 : 0;
        for (int i = 1; i < words.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + (check[i] == true ? 1 : 0);
        }

        vector<int> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            auto l = queries[i][0];
            auto r = queries[i][1];

            ans[i] = l == 0 ? prefixSum[r] : prefixSum[r] - prefixSum[l-1];
        }
        return ans;
    }
};
