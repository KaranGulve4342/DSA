// LEETCODE 374

/*
class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int ans = guess(mid);

            if(ans == 0) return mid;
            else if(ans == 1) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
*/