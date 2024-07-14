// LEETCODE 3217

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        
        for(auto num : nums){
            st.insert(num);
        }
        
        ListNode* k = new ListNode(-1);
        
        k->next = head;
        
        ListNode* curr = k;
        
        while (curr->next != NULL) {
            
            if (st.find(curr->next->val) != st.end()) {
                ListNode* t = curr->next;
                curr->next = curr->next->next;
                delete t;
            } 
            else {
                curr = curr->next;
            }
        }
        
        return k->next;
    }
};