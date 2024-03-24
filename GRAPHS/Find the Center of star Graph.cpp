// LEETCODE 1791

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCenter(vector<vector<int> >&edges){
        int a = edges[0][0];
        int b = edges[0][1];

        int c = edges[1][0];
        int d = edges[1][1];

        return (c == a || c == b) ? c : d;
    }
};

int main()
{
    
    
    return 0;
}

/*
int findCenter(vector<vector<int> >&edges){
    int a = edges[0][0];
    int b = edges[0][1];
    
    int c = edges[1][0];
    int d = edges[1][1];

    return (c == a || c == b) ? c : d;
}
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxDegree = 0;
        int maxNode = 0;

        for(auto &neighbours : adj){
            int node = neighbours.first;
            int degree = neighbours.second.size();

            if (degree > maxDegree) {
                maxDegree = degree;
                maxNode = node;
            }
        }
        return maxNode;
    }
};