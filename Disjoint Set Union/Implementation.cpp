#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}
int find(int v){
    if(v == parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        // Union by size
        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) make(i);
    
    vector<pair<int,int>> edges;
    for (int i=1;i<=k;i++){
        int u,v;
        cin >> u >> v;
        Union(u, v);
    }
    int connectedComponents = 0;
    for(int i = 1;i <= n;i++){
        if(find(v) == v) connectedComponents++;
    }
    cout<<connectedComponents;
    return 0;
}   