// LEETCODE 2097

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjList;

        unordered_map<int, int> degree;

        for(auto pair : pairs){
            auto u = pair[0];
            auto v = pair[1];

            adjList[u].push_back(v);
            degree[u]++;
            degree[v]--;
        }

        int start = pairs[0][0];

        for(auto it : degree){
            if(it.second == 1){
                start = it.first;
                break;
            }
        }

        stack<int> st;
        st.push(start);

        vector<int> sequence;

        while(!st.empty()){
            int x = st.top();

            while(adjList[x].size() > 0){
                int y = adjList[x].back();
                adjList[x].pop_back();
                st.push(y);
                x = y;
            }

            int last = st.top();
            st.pop();
            sequence.push_back(last);
        }

        reverse(sequence.begin(), sequence.end());

        int n = sequence.size();

        vector<vector<int>> ans;

        for(int i = 0;i < n-1;i++){
            ans.push_back({sequence[i], sequence[i+1]});
        }

        return ans;
    }
};