// LEETCODE 3244

class Solution {
public:
    set<int> st;
    int n;

    void eraseMiddleNodes(int x, int y){
        auto start = st.lower_bound(x);
        auto end = st.upper_bound(y);

        st.erase(start, end);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        this->n = n;

        st.clear();

        for(int i = 0;i < n;i++){
            st.insert(i);
        }

        vector<int> ans;

        for(auto query : queries){
            int x = query[0];
            int y = query[1];

            eraseMiddleNodes(x + 1, y - 1);

            ans.push_back(st.size() - 1);
        }

        return ans;
    }
};