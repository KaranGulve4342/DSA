/*
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;
        if(l1 == NULL) return L2;
        if(l2 == NULL) return l1;

        ListNode* a = l1;
        ListNode* b = l2;

        ListNode* c = new ListNode(0);
        ListNode* temp = c;

        while(a!=NULL || b!=NULL){
            int x = a!=NULL ? a->val : 0;
            int y = b!=NULL ? b->val : 0;
            int sum = x + y + carry;
            temp->next = newListNode(sum%10);
            carry = sum/10;
            temp = temp->next;
            if(a!=NULL) a = a->next;
            if(b!=NULL) b = b->next;
        }
        if(carry != NULL){
            temp->next = new ListNode(carry);
        }
    }
}
*/