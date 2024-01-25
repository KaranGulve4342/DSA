// LEETCODE 1046

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lastStoneWeight(vector<int>& arr){
        while(arr.size() > 1){
            sort(arr.begin(), arr.end());
            int x = arr[arr.size() - 1];
            arr.pop_back();

            int y = arr[arr.size() - 1];
            arr.pop_back();

            if(x != y) ans.push_back(x - y);
        }

        if(arr.size() == 1){
            return arr[0];
        }
        else{
            return 0;
        }
    }
}