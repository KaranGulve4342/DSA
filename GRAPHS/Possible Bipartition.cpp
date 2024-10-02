// LEETCODE 886

class Solution {
public:
    bool bfs(int start, unordered_map<int, vector<int>>& adjList, vector<int>& color){
        color[start] = 1;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto neighbour : adjList[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = 1 - color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList(n+1);

        for(auto dislike : dislikes){
            auto u = dislike[0];
            auto v = dislike[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i = 1;i <= n;i++){
            if(color[i] == -1){
                if(!bfs(i, adjList, color)){
                    return false;
                }
            }
        }

        return true;
    }
};