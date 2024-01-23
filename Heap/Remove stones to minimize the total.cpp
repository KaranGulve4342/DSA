// LEETCODE 1962

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k-- ){
            int temp = pq.top() - (pq.top())/2;
            pq.pop();
            pq.push(temp);
        }

        int sum = 0;

        while(pq.size() > 0){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};