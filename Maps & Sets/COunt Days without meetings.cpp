class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;

        sort(meetings.begin(), meetings.end());

        vector<pair<int, int>> vp;
        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end + 1) {
                end = max(end, meetings[i][1]);
            } else {
                vp.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        vp.push_back({start, end});

        if (vp[0].first > 1) {
            ans += vp[0].first - 1;
        }

        for (int i = 1; i < vp.size(); ++i) {
            ans += vp[i].first - vp[i - 1].second - 1;
        }

        if (vp.back().second < days) {
            ans += days - vp.back().second;
        }

        return ans;
    }
};