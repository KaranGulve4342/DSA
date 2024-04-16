// LEETCODE 2178

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};

        vector<long long> ans;

        long long i = 2;
        long long curr = 0;

        while((curr + i) <= finalSum){
            ans.push_back(i);
            curr += i;
            i += 2;
        }

        int n = ans.size();

        ans[n-1] += finalSum - curr;

        return ans;
    }
};