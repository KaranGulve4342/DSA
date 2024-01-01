// LEETCODE 19

/*
ListNode* removeNthFromEnd)ListNode* head,int n){
    ListNode* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    if(n == len){
        head = head->next;
        return head;
    }

    // nth from end = (len-n+1)th from start
    
    temp = head;
    for(int i=1;i <= len - n;i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}


*/

/*
Using slow and Fast Pointers

class Solution{
    public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
        ListNode* slow = head;
        ListNode* fast = head;

        // traverse fast to (n+1) steps
        for(int i = 1;i <= n+1;i++){
            if(fast == NULL) return head->next;
            fast = fast->next;
        }

        // move slow and fast at same pace
        whie(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now the slow is exactly at left of the nth node 
        slow->next = slow->next->next;
        return head;
    }
}

*/