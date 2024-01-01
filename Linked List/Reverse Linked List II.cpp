// LEETCODE 92

/*
class Solution{
    ListNode* reverseList(ListNode* head){
        ListNode*prev = NULL;
        ListNode* curr=  head;
        ListNode* Next = head;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(left == right) return head;
        Listnode* a = NULL;
        Listnode* b = NULL;
        Listnode* c = NULL;
        Listnode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp != NULL){
            if(n == left - 1) a = temp;
            if(n == left) b = temp;
            if(n == right) c = temp;
            if(n == right + 1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a != NULL) a->next = NULL;
        c->next = NULL;
        c = reverseList(b);
        if(a != NULL) a->next = c;
        b->next = d;
        if(a->next != NULL) return head;
        return c;

    }
}
*/