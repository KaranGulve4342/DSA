// LEETCODE 876

// Middle of the linked List

/* 
class Solution{
    public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}
*/

/*
ListNode* middleNode(ListNode* head){
    int len = 0;
    listNode* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    int midIdx = len/2;
    ListNode*mid = head;
    for(int i = 0;i <= midIdx;i++){
        mid = mid->next;
    }
    return mid;
}
*/