// LEETCODE 3159

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();

        vector<int> ans;
        vector<int> occurrences;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == x){
                occurrences.push_back(i);
            }
        }

        for(auto query : queries){
            if(query <= occurrences.size()){
                ans.push_back(occurrences[query - 1]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};