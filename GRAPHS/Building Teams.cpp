#include<bits/stdc++.h>
using namespace std;

bool bfs(int start, unordered_map<int, vector<int>>& adjList, vector<int>& teams){
    queue<int> q;
    q.push(start);

    teams[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbour : adjList[node]){
            if(teams[neighbour] == -1){
                teams[neighbour] = 3 - teams[node];
                q.push(neighbour);
            }
            else if(teams[neighbour] == teams[node]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adjList(n+1);

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> teams(n+1, -1);

    for(int i = 1;i <= n;i++){
        if(teams[i] == -1){
            if(!bfs(i, adjList, teams)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    
    for(int i = 1;i <= n;i++){
        cout<<teams[i]<<" ";
    }
    cout<<endl;
    return 0;
}