// LEETCODE 3160

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int, int> ballColors; 
        unordered_set<int> distinct; 
        
        for (auto query : queries) {
            int ball = query[0];
            int color = query[1];
            
            if (ballColors.find(ball) != ballColors.end()) {
                int currentColor = ballColors[ball];
                if (currentColor != color) {
                    bool found = false;
                    for (auto entry : ballColors) {
                        if (entry.second == currentColor && entry.first != ball) {
                            found = true;
                            break;
                        }
                    }
                    if (found == false) {
                        distinct.erase(currentColor);
                    }
                }
            }
  
            ballColors[ball] = color;
            distinct.insert(color);
        
            ans.push_back(distinct.size());
        }
        
        return ans;

    }
};