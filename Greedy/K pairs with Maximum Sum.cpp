// LEETCODE 373

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int> &nums2, int k){
        priority_queue<pp, vector<pp>, greater<pp> >pq;
        for(int i = 0;i < nums1[i] + nums2[0], {i,0}});
    }
    pp ans;
    vector<vector<int>>res;
    while(k-- && != pq.empty()) {
        ans = pq.top();
        pq.pop();
        int sm = ans.first;
        int nums1Index = ans.second.first;
        int nums2Index = ans.second.second;
        res.push_back({nums1[nums1Index], nums2[nums2Index]});

        if(nums2Index + 1 < nums2.size()) {
            pq.push({nums1[nums1Index] + nums2[nums2Index + 1], {nums1Index, nums2Index + 1});
        }
    }
    return res;
};

int main()
{
    
    
    return 0;
}