// LEETCODE  2406

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int count = 1;
        vector<int> left;
        vector<int> right;

        for(int i = 0;i < n;i++){
            left.push_back(intervals[i][0]);
            right.push_back(intervals[i][1]);
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int i = 1;
        int j = 0;

        int maxi = 1;

        while(i < n && j < n){
            if(left[i] <= right[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};