// LEETCODE 797

class Solution {
public:
    void solve(int node, vector<vector<int> >& graph, vector<int> &temp, vector<vector<int> >& ans){
        temp.push_back(node);
        if(node == graph.size() - 1){
            ans.push_back(temp);
        }
        else{
            for(auto child : graph[node]){
                solve(child, graph, temp, ans);
            }
        }
        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        vector<int> temp;

        solve(0, graph, temp, ans);
        return ans;
    }
};