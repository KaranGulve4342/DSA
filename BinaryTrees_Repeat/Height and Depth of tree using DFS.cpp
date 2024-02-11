// HEIGHT AND DEPTH OF A TREE USING DFS

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>g[N];

void dfs(int vertex, int parent){
    // Take action on vertex after entering the vertex
    vis[vertex] = true;
    for(int child : g[vertex]){
        // Take action on child before entering the child node
        if(c
        if(vis[child]) continue;
        dfs(child);
        // Take action on child after exiting child node
    }
}

int main(){
    
    return 0;
}