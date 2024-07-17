// LEETCODE 526. Beautiful Arrangement

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int pos, int &count, vector<bool>& visited){
        if(pos > n){
            count++;
        }

        for(int i = 1;i <= n;i++){
            if(!visited[i] && (pos%i == 0 || i%pos == 0)){
                visited[i] = true;
                solve(n, pos + 1, count, visited);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        int count = 0;
        solve(n, 1, count, visited);
        return count;
    }
};