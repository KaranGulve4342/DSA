// LEETCODE 1046

/*
class Solution{
public:
    int lastStoneWeight(vector<int>& stones){
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int p1 = pq.top(); // max element
            pq.pop();
            int p2 = pq.top(); // 2nd Max element
            pq.pop();

            int diff=  abs(p1 - p2);
            if(diff != 0) pq.push(diff);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};
*/