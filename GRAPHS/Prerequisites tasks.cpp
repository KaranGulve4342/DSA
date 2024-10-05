// GFG PRACTICE 

// USING TOPO SORT

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int, vector<int>> adjList;
	    
	    for(int i = 0;i < P;i++){
	        auto u = prerequisites[i].first;
	        auto v = prerequisites[i].second;
	        
	        adjList[u].push_back(v);
	    }
	    
	    vector<int> indegree(N, 0);
	    queue<int> q;
	    
	    for(int i = 0;i < N;i++){
	        for(auto it : adjList[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0;i < N;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        count++;
	        
	        for(auto neighbour : adjList[node]){
	            indegree[neighbour]--;
	            
	            if(indegree[neighbour] == 0){
	                q.push(neighbour);
	            }
	        }
	    }
	    
	    
	    return count == N;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends