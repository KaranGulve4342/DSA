// Coding Ninjas
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int>g[N];
int vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        int currVertex = q.front();
        q.pop();
        cout<<currVertex<<" ";
        for(int child : g[currVertex]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[currVertex] + 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0;i < n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);

    cout<<endl;

    for(int i = 1;i <= n;i++){
        cout<<i<<" "<<level[i]<<endl;
    }

    return 0;
}




/*

#include<unordered_map>
#include<queue>
#include<list>
#include<set>

void prepareAdjList(unordered_map<int, set<int> >&adjList, vector<pair<int, int>> &edges) {
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int> >&adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, set<int> >adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges)

    for(int i = 0;i < vertex;i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}


*/