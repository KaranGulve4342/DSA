//  LEETCODE 210

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int, list<int>> adjList;

        for(auto x : prerequisites){
            int u = x[0];
            int v = x[1];

            adjList[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0;i < numCourses;i++){
            for(auto neighbour : adjList[i]){
                indegree[neighbour]++;
            }
        }

        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto neighbour : adjList[node]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};