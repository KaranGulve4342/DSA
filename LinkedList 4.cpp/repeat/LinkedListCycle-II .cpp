/*
class Solution{
    public:
    ListNode* slow = head;
    listNode* fast = head;
    bool flag = false;
    while(fast!=NUll && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }
    if(flag == false) return NULL;
    else{
        ListNode* temp = head;
        while(temp!=slow){
            slow = slow->next;
            temp = temp->next;
        }
        return slow;
    }
}
*/