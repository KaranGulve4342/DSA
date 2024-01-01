// LEETCODE 253

/*
class Solution{
public:
    int minMeetingRoom(vector<vector<int>>& intervals){
        if(intervals.size() == 0) return 0;

        vector<int> starting;
        vector<int> ending;
        for(auto ele : intervals){
            starting.push_back(ele[0]);
            ending.push_back(ele[s[1]);
        }
        sort(starting.begin(), starting.ending());
        sort(ending.begin(), ending.end());

        int ans = 0;
        int rooms = 0;
        int i = 0;
        int j = 0;
        while(i < starting.size() && j < ending.size()){
            if(starting[i] < ending[i]){
                // meeting is starting
                rooms++;
                ans = max(ans, rooms);
                i++;
            }
            else if(starting[i] > ending[i]){
                // meeting is ending
                rooms--;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};
*/