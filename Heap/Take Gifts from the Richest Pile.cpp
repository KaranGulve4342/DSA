// LEETCODE 2558

/*
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int gift : gifts){
            pq.push(gift);
        }

        for(int i = 0;i < k;i++){
            int max_gift = pq.top();
            pq.pop();

            int remaining_gift = sqrt(max_gift);
            pq.push(remaining_gift);
        }

        long long total_Remaining = 0;
        while(!pq.empty()){
            total_Remaining += pq.top();
            pq.pop();
        }
        return total_Remaining;
    }
};
*/