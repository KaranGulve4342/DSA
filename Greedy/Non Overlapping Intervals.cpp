// LEETCODE 435

// METHOD 1 : SORTING ON THE BASIS OF ENDTIME
/*
bool cmp(vector<int> &i1, vector<int> &i2){
    return i1[1] < i2[1];
}
class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] < lastEndTime){
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
}
*/

// METHOD 2 
/*
bool cmp(vector<int> &i1, vector<int> &i2){
    return i1[1] < i2[1];
}
class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] < lastEndTime){
                ans++;
                lastEndTime = min(lastEndTime, intervals[i]);
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
}
*/
