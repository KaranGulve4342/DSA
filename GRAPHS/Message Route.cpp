#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adjList;

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n+5, false);

    vector<int> parents(n+5, -1);
    queue<int> q;
    q.push(1);

    visited[1] = true;

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        visited[node] = true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parents[neighbour] = node;

                q.push(neighbour);
            }
        }
    }

    if(!visited[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    stack<int> st;

    int curr = n;

    while(curr != -1){
        st.push(curr);
        curr = parents[curr];
    }

    cout<<st.size()<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}