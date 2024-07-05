// LEETCODE 2058

#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        int minDistance = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currIdx = 1;
        int prevCriticalIdx = 0;
        int firstCriticalIdx = 0;

        while(curr->next != NULL){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                if(prevCriticalIdx == 0){
                    prevCriticalIdx = currIdx;
                    firstCriticalIdx = currIdx;
                }
                else{
                    minDistance = min(minDistance, currIdx - prevCriticalIdx);
                    prevCriticalIdx = currIdx;
                }
            }

            currIdx++;
            prev = curr;
            curr = curr->next;
        }

        if(minDistance != INT_MAX){
            int maxDistance = prevCriticalIdx - firstCriticalIdx;
            ans = {minDistance, maxDistance};
        }

        return ans;
    }
};