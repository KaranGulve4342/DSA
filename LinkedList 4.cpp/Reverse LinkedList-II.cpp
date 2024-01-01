/*

class Solution{
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr->next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head,int left,int right){
        if(left == right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp){
            if(n == left-1) a = temp;
            if(n == left) b = temp;
            if(n == right) c = temp;
            if(n == right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a) a->next = NULL;
        c->next = NULL;
        c = reverseList(b);
        if(a) a->next = c;
        b->next = d;
        if(a) return head;
        return c;
    }
}

*/
/*
class Solution {
public:
    ListNode* getNodeAt(ListNode* head, int idx){
        ListNode* temp = head;
        while(idx > 0 && temp != NULL){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        if (left == right || head == NULL || head->next == NULL) return head;
        int n = 0;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        while(left < right){
            ListNode* L = getNodeAt(head,left-1);
            ListNode* R = getNodeAt(head,right-1);

            int t = L->val;
            L->val = R->val;
            R->val = t;
            left++;
            right--;

        }
        return head;   
    }
};
*/