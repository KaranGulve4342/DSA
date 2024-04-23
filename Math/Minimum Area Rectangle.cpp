// LEETCODE 939

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INT_MAX;
        
        set<vector<int>> st;

        for (const auto& point : points) {
            st.insert(point);
        }

        for (const auto& point1 : points) {
            for (const auto& point2 : points) {

                if (point1[0] != point2[0] && point1[1] != point2[1]) {

                    if (st.find({point1[0], point2[1]}) != st.end() &&
                        st.find({point2[0], point1[1]}) != st.end()) {
                        minArea = min(minArea, abs(point2[0] - point1[0]) * abs(point2[1] - point1[1]));
                    }
                }
            }
        }

        return minArea == INT_MAX ? 0 : minArea;


    }
};