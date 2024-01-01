//  LEETCODE 142

/*
class Solution{
public:
    ListNode* slow = head;
    Listnode* fast = head;
    bool flag = false; // no cycle
    while(fast != NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow = fast){
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