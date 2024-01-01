// LEETCODE 141

/*
class Solution{
public:
    ListNode* slow = head;
    ListNode fast = head;
    whle(fast!=NULL && fast!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}   
*/