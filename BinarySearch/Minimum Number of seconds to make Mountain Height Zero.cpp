// LEETCODE 3296

class Solution {
public:
    long long findMaxTimes(int num, long long timeLimit){
        long long lo = 0;
        long long hi = 1e5;

        long long ans = 0;

        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;

            long long timeRequired = 1LL * mid * (mid + 1)/2 * num;

            if(timeRequired <= timeLimit){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
    bool check(long long timeLimit, int mountainHeight, vector<int>& workerTimes){
        long long totalHeight = 0;

        for(int i = 0;i < workerTimes.size();i++){
            totalHeight += findMaxTimes(workerTimes[i], timeLimit);
        }

        return totalHeight >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0;
        long long hi = 1e18;

        long long ans = 1e18;

        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;

            if(check(mid, mountainHeight, workerTimes)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};