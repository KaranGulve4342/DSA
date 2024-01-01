// LEETCODE 1721

/*
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        if(k > n || k <= 0) return head;

        for(int i = 1;i < k;i++){
            slow = slow->next;
        }
        
        for(int j =1;j < n - k + 1;j++){
            fast = fast->next;
        }

        int TEMP = slow->val;
        slow->val = fast->val;
        fast->val = TEMP;

        return head;
    }
};
*/