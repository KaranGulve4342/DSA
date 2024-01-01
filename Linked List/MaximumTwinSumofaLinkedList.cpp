// LEETCODE 2130

/*
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL || head->next == NULL) return 0;

        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* Next=  slow->next;
        slow->next = NULL;
        while(curr!=NULL){
            Next = curr->next;
            curr->next = prev;
            prev=  curr;
            curr = Next;
        }

        
        ListNode* first = head;
        ListNode* second=  prev;
        int maxSum = 0;
        while(first != NULL && second != NULL){
            int sum = first->val + second->val;

            first = first->next;
            second = second->next;
            maxSum = max(sum,maxSum);
        }
        return maxSum;
        
        
    }
};
*/