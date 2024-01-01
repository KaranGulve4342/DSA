// LEETCODE 1048

/*
class Solution{
    int longestChain(vector<string>& words){
        unordered_map<string, int> dp;
        int ans = 0;
        sort(words.begin(), words.end(), sortByLength);

        for(string word : words){
            // remove characters one by one from word and check if the obtained string is predecessor -> if it exists in map.
            for(int i = 0;i < word.length();i++){
                string predecessor = word.substr(0, i) + word.substr(i+1);
                dp[word] = max(dp[word], dp[predecessor] + 1);
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
    bool sortByLength(string &s1, string &s2){
        return s1.length() < s2.length();
    }
}
*/