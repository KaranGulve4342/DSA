/*
class Solution{
    public:
    ListNode* removeNthFromEnd(Listnode* head,int n){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        if(n == len){
            head = head->next;
            return head;
        }
        // nth from end = (len-n+1)th from start
        int m = len - n + 1;
        int idx = m-1; // the idx of node to be deleted
        temp = head;
        for(int i = 1;i <= idx - 1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
}
*/
// Using slow and fast pointers
/*
class Solution{
    public:
    ListNode* removenthFromEnd(ListNode* head,int n){
        ListNode* slow = head;
        ListNode* fast = head;
        // traverse fast to (n+1) steps
        for(int i = 1;i <= n+1;i++){
            if(fast == NULL) return head->next;
            fast =  fast->next;
        }
        // move slow and fast at same pace
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now the slow is exactly at left of the 
        slow->next = slow->next->next;
        return head;
    }   
}
*/


