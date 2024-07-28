class Solution {
public:
    int solve(vector<vector<int>>& adjList, int s, int t1, int t2, int n){
        queue<int> q;
        vector<int> visited(n+4, 0);
        q.push(s);
        visited[s] = 1;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adjList[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        return visited[t1] || visited[t2];
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        
        vector<pair<pair<int, int>, int>> arr(n);
        vector<vector<int>> adjList(n + 4);
        
        for(int i = 0;i < n;i++){
            arr[i] = {{circles[i][0], circles[i][1]}, circles[i][2]};
        }
        for(int i = 0;i < n;i++){
            if(arr[i].first.first <= arr[i].second){
                adjList[n].push_back(i);
                adjList[i].push_back(n);
            }
            if(X - arr[i].first.first <= arr[i].second){
                adjList[n + 2].push_back(i);
                adjList[i].push_back(n + 2);
            }
            if(arr[i].first.second <= arr[i].second){
                adjList[n + 1].push_back(i);
                adjList[i].push_back(n + 1);
            }
            if(Y - arr[i].first.second <= arr[i].second){
                adjList[n + 3].push_back(i);
                adjList[i].push_back(n + 3);
            }
            for(int j = i+1;j < n;j++){
                double d =  sqrt(pow(arr[i].first.first - arr[j].first.first, 2) + pow(arr[i].first.second - arr[j].first.second, 2));
                if(arr[i].second + arr[j].second >= d){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        return !(solve(adjList, n, n + 1, n + 2, n + 4) || solve(adjList, n+3, n + 2, n + 1, n + 4)); 
    }
};