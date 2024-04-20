// LEETCODE 539

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int mn = INT_MAX;
        sort(timePoints.begin(), timePoints.end());

        for (int i = 1; i < timePoints.size(); i++) {
            string str1 = timePoints[i];
            int hour1 = stoi(str1.substr(0, 2));
            int minute1 = stoi(str1.substr(3));

            int time1 = hour1 * 60 + minute1;

            string str2 = timePoints[i - 1];
            int hour2 = stoi(str2.substr(0, 2));
            int minute2 = stoi(str2.substr(3));

            int time2 = hour2 * 60 + minute2;

            int diff = min(time1 - time2, 24 * 60 - time1 + time2);
            mn = min(diff, mn);
        }

        // Consider the circular difference between the last and first time points
        string lastTime = timePoints.back();
        int lastHour = stoi(lastTime.substr(0, 2));
        int lastMinute = stoi(lastTime.substr(3));
        int lastTimeMinutes = lastHour * 60 + lastMinute;

        string firstTime = timePoints.front();
        int firstHour = stoi(firstTime.substr(0, 2));
        int firstMinute = stoi(firstTime.substr(3));
        int firstTimeMinutes = firstHour * 60 + firstMinute;

        int circularDiff = min(lastTimeMinutes - firstTimeMinutes, firstTimeMinutes + 24 * 60 - lastTimeMinutes);
        mn = min(circularDiff, mn);

        return mn;
    }
};