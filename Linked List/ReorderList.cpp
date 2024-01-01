// LEETCODE 143

/*
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    void reorderList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is at the leftMiddle/middle
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // for breaking the lists
        // merge these two -a and b respectively
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA != NULL && tempB != NULL){
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;
            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head = c->next;
    }
}
*/