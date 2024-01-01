// LEETCODE 1642

/*
class Solution{
public:
    int furthestBuilding(vector<int>& heights, int brickes, int ladders){
        priority_queue<int>pq;
        int i = 0;
        int bricksUsed = 0;
        for(i = 0;i < heights.size() - 1;i++){
            if(heights[i] >= heights[i+1]){
                continue;
            }
            int heightDiff = heights[i + 1] - heights[i];
            if(heightDiff + bricksUsed <= bricks){
                // do we have enough bricks
                bricksUsed += heightDiff;
                pq.push(heightDiff);
            }
            else if(ladders > 0){
                if(!pq.empty() && pq.top() > heightDiff){
                    bricksUsed = bricksUsed - pq.top() + heightDiff;
                    pq.pop();
                    pq.push(heightDiff);
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};
*/