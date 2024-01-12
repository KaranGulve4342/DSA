// LEETCODE 147

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ans = NULL;

        while(head != NULL){
            ListNode* curr = head;
            head = head->next;

            if(ans == NULL || curr->val < ans->val){
                curr->next = ans;
                ans = curr;
            }
            else{
                ListNode* temp = ans;

                while(temp->next != NULL && temp->next->val < curr->val){
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        return ans;
    }
};