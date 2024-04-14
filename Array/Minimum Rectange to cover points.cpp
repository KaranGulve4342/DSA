// LEETCODE 3111

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        
        int ans = 1;
        int min_x = points[0][0];
        
        for(int i = 1;i < points.size();i++){
            int x = points[i][0];
            
            if(x - min_x > w){
                min_x = x;
                ans++;
            }
        }
        
        return ans;
        
    }
};