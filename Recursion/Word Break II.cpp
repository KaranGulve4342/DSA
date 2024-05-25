// LEETCODE 140

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, string s, string temp, vector<string>& ans, unordered_set<string> &uset){
        if(idx == s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string curr = "";
        for(int i = idx;i < s.length();i++){
            curr.push_back(s[i]);
            if(uset.find(curr) != uset.end()){
                solve(i+1, s, temp + curr + " ", ans, uset);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> uset;

        int n = s.length();

        for(auto word : wordDict){
            uset.insert(word);
        }

        solve(0, s, "", ans, uset);
        return ans;
    }
};