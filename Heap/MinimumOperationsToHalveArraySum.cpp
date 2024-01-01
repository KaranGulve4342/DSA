// LEETCODE 2208

/*
class Solution{
public:
    int halveArray(vector<int>& nums){
        priority_queue<double> pq;
        double totalSum = 0.0;
        for(int i = 0;i < nums.size();i++){
            totalSum += nums[i];
            pq.push(nums[i]*1.0);
        }
        double rs = ts / 2.0;
        int ans = 0;
        while(ts > rs){
            double ele = pq.top();
            pq.pop();
            ts -= (ele)/2.0;
            pq.push((ele/2.0));
            ans++;
        }
        return ans;
    }
}
*/