// CODING NINJAS

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int> >&vec, int vertices, int edges, int source){
    // create adjacency list
    unordered_map<int, list<pair<int, int> > >adj;
    for(int i = 0;i < edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // creation of distance array with infinite value initially
    vector<int> dist(vertices);

    for(int i = 0;i < vertices;i++){
        dist[i] = INT_MAX;
    }
    
    // creation of set on basis (distance, node)
    set<pair<int, int> >st;

    // initialise distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));
    
    while(!st.empty()){
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        // traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // if record found, then erase it

                if(record != st.end()){
                    st.erase(record);
                }

                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;

}

/*

class Solution{
public:
    // Funtion to find the shortest distance of all the vertices from the source vertex S.

    vector<int> dijkstra(int V, vector<vector<int> >adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i = 0;i < V;i++){
            dist[i] = 1e9;
        }

        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
}

*/