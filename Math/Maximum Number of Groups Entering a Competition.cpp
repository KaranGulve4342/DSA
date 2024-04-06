// LEETCODE 2358

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();

        int groups = 0;
        int sum = 0;

        while(sum + groups < n){
            groups++;
            sum += groups;
        }

        return groups;
    }
};