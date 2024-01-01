// LEETCODE  1679


/*
class Solution{
public:
    int maxOperations(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int cnt = 0;

        for(auto x : nums) mp[x]++;

        for(auto x : nums){
            int diff = k - x;

            if(diff == x){
                cnt += (mp[diff]/2);
                mp.erase(x);
            }
            else if(mp.count(diff)){
                cnt += min(mp[diff], mp[x]);
                mp.erase(x);
                mp.erase(diff);
            }
        }
        return cnt;
    }
}
*/


/*
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-  1;
        int count = 0;

        while(i < j){
            if(nums[i] + nums[j] == k){
                count++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] > k){
                j--;
            }
            else i++;
        }
        return count;
    }
};
*/