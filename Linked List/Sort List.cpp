// LEETCODE 148

/*

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a,Listnode* b){
        // SC = O(1)
        Listnode* c = new ListNode(100);
        ListNode* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a == NULL) temp->next = b;
        else temp->next = a;
        temp = temp->next;
    }
    ListNode* sortList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL) return head;
        // to find the left middle
        ListNode* slow = head;
        Listnode* fast = head;
        while(fast -> next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now slow is at left middle
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = merge(a,b);
        return c;
    }
};

*/