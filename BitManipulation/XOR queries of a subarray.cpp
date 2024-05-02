// LEETCODE 1310

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 1;i < arr.size();i++){
            arr[i] ^= arr[i-1];
        }

        for(int i = 0;i < queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == 0){
                ans.push_back(arr[end]);
            }
            else{
                ans.push_back(arr[start - 1] ^ arr[end]);
            }
        }

        return ans;

    }
};