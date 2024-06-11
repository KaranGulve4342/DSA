// LEETCODE 496

// Given two arrays, find the next greater element of each element in the first array in the second array.
// The next greater element of an element in an array is the first element to its right which is greater than it.
// If it does not exist, output -1 for that element.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation:
// For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
// For number 1 in the first array, the next greater number for it in the second array is 3.
// For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation:
// For number 2 in the first array, the next greater number for it in the second array is 3.
// For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

// Constraints:
// 1 <= nums1.length, nums2.length <= 104
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);

        stack<int> st;
        unordered_map<int, int> umap;

        for(int i = 0;i < nums2.size();i++){
            while(!st.empty() && nums2[i] > st.top()){
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0;i < nums1.size();i++){
            if(umap.find(nums1[i]) != umap.end()){
                ans[i] = umap[nums1[i]];
            }
        }

        return ans;
    }
};