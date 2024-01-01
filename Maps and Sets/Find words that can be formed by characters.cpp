// LEETCODE 1160

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> umap;

        for(int i = 0;i < chars.length();i++){
            umap[chars[i]]++;
        }
        for(int i = 0;i < words.size();i++){
            unordered_map<char, int> mp;
            string s = words[i];
            for(int j = 0;j < s.length();j++){
                mp[s[j]]++;
            }
            bool flag = true;
            for(int k = 0;k < s.length();k++){
                if(mp[s[k]] > umap[s[k]]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans += s.length();
            }
        }

        return ans;
    }
};